#include <dpp/urler.hpp>

// Set common default values in the constructor
dpp::urler::urler() {
  m_method = "GET";
  m_http_ver = 11;
  m_path = "/";
  m_body = "";
}

void dpp::urler::set_method(std::string t_method) { m_method = t_method; }
void dpp::urler::set_http_ver(unsigned int t_http_ver) { m_http_ver = t_http_ver; }
void dpp::urler::set_path(std::string t_path) { m_path = t_path; }
void dpp::urler::set_body(std::string t_body) { m_body = t_body; }

void dpp::urler::set_header(std::string t_header, std::string t_value) {
  m_headers[t_header] = t_value;
}
void dpp::urler::delete_header(std::string t_header) {
  m_headers[t_header] = "-no-";
  // Check how to delete properties of a json
}

dpp::http_res dpp::urler::perform(std::string t_url) {
  using json = nlohmann::json;
  using tcp = boost::asio::ip::tcp;
  namespace ssl = boost::asio::ssl;
  namespace http = boost::beast::http;
  boost::asio::io_context ioc;

  ssl::context ctx{ssl::context::sslv23_client};

  load_root_certificates(ctx); // SSL shit

  tcp::resolver resolver{ioc};
  ssl::stream<tcp::socket> stream{ioc, ctx};

  // Another SSL shit
  if(! SSL_set_tlsext_host_name(stream.native_handle(), t_url.c_str())) {
    boost::system::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
  }

  auto const results = resolver.resolve(t_url, "443"); // Resolving

  boost::asio::connect(stream.next_layer(), results.begin(), results.end()); // Connecting

  stream.handshake(ssl::stream_base::client); // SSL shit again

  http::request<http::string_body> req{http::string_to_verb(m_method), m_path.c_str(), m_http_ver};
  for (json::iterator it = m_headers.begin(); it != m_headers.end(); it++) {
    if (it.value() != "-no-") {
      // Setting of the headers
      req.set(it.key(), it.value().get<std::string>());
    }
  }
  
  if (m_body.size() > 0) {
    req.body() = m_body;
    req.prepare_payload();
  }

  // Write request, uncomment to debug
  std::cout << req << std::endl;
  
  http::write(stream, req); // SENDING

  boost::beast::flat_buffer buffer;

  http::response<http::dynamic_body> res;

  http::read(stream, buffer, res);

  http_res ret_res;
  std::ostringstream os;
  os << boost::beast::buffers(res.body().data());
  ret_res.body = os.str();

  ret_res.base = "lol"; // res.base();

  boost::system::error_code ec;
  stream.shutdown(ec);
  if(ec == boost::asio::error::eof) {
    ec.assign(0, ec.category());
  }
  return ret_res;
        //std::string str_res;
        //std::ifstream(&res) >> str_res
        // return res;
        // If we get here then the connection is closed gracefully
}
