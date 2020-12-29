#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <chrono>
#include<thread>
class server
{
public:
	server(int aPort = 443);
	~server();

	bool start();
	void setCertPath(std::string);
	void setKeyPath(std::string);
	void setPathForCA(std::string);
private:
	int m_socket{ -1 };
	int m_port{ 443 };
	bool _ssl_init();
	bool _socket_init();
	void _client_processing(int, std::string);

	std::string   m_certificate_path;
	std::string   m_key_path;
	std::string   m_ca_path;
	std::string   m_html_data;

	std::string   m_start_date_time;
	size_t        m_get_request_count{ 0 };

	SSL_METHOD* mp_ssl_method{ nullptr };
	SSL_CTX* mp_ssl_context{ nullptr };

	std::vector<char> m_fav_icon_buffer;
};

#endif // SERVER_HPP