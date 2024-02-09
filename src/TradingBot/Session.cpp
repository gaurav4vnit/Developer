#include <fstream>
#include <string>
#include <iostream>
#include <boost/asio/io_context.hpp>
#include <`>
using namespace std;

class Session
{
public:
    Session()
    {
        parseData();
    }
    string getField(const string &line, const string fieldname)
    {
        auto pos = line.find(fieldname);
        if(pos!= std::string::npos)
        {
            //cout<<line.substr(fieldname.length()+1,line.length()-fieldname.length());
            return std::move(line.substr(fieldname.length()+1,line.length()-fieldname.length()));
        }
        return "";
    }
    void parseData()
    {
        string myText;
        ifstream m_buffer("data/session_data.txt");
        while (getline (m_buffer, myText)) 
        {
            //Why below does not work?
            //if(APIKEY.size()==0) APIKEY(std::move(getField(myText,"APIKEY"))); 
            //if(SESSION.size()==0) SESSION(std::move(getField(myTsext,"SESSION")));
            //if(SECRETKEY.size()==0) SECRETKEY(std::move(getField(myText,"SECRETKEY")));
            if(APIKEY.empty()) APIKEY=std::move(getField(myText,"APIKEY"));   
            if(SESSION.empty()) SESSION = std::move(getField(myText,"SESSION"));
            if(SECRETKEY.empty()) SECRETKEY = std::move(getField(myText,"SECRETKEY"));
        }            
        cout<<APIKEY<<endl<<SESSION<<endl<<SECRETKEY<<endl;
    }
  /*  void login()
    {
        //https://api.icicidirect.com/apiuser/login?api_key=AppKey

        net::io_context ioc;
        tcp::resolver resolver{ ioc };

        // Look up the domain name
        auto const results = resolver.resolve("api.icicidirect.com","https");
        std::cout << "Domain name looked up\n";
        
        // Create a TCP socket and connect it to the server
        beast::tcp_stream stream(io_context);
        stream.connect(results);

        // Set up an HTTP request message
        http::request<http::string_body> req{http::verb::get, "/apiuser/login?api_key=AppKey", 11};
        req.set(http::field::host, "api.icicidirect.com");
        req.set(http::field::user_agent, "Boost Beast");

        // Send the HTTP request
        http::write(stream, req);

        // Receive the HTTP response
        beast::flat_buffer buffer;
        http::response<http::string_body> res;
        http::read(stream, buffer, res);

        // Print the response status code and body
        std::cout << "Response code: " << res.result_int() << std::endl;
        std::cout << "Response body: " << res.body() << std::endl;
    }
*/
private:
    string APIKEY;
    string SECRETKEY;
    string SESSION;

};

