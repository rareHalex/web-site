#ifndef HTTP_REQUEST_HHP
#define HTTP_REQUEST_HPP
#include<string>
class http_request
{
public:
	enum class eType
	{
		Unknown = 0,
		GET,
		PUT,
		DELETE
	};
	http_request();

	void parse(const char*);
	const eType& type();
	const std::string& uri() const;
private:
	void _parse_request_line(std::string&);
	eType m_type{ eType::Unknown };
	std::string m_uri;
 };

#endif 