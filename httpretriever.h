#ifndef HTTPRETRIEVER_H
#define HTTPRETRIEVER_H

#include <string>

#include <QString>
#include <QStringList>

#include <curl/curl.h>

class HttpRetriever
{
  public:
    explicit HttpRetriever(const char *url);
    ~HttpRetriever();
    QStringList getHtmlContents() const;
  private:
    bool initializeConnection();
    static int writer(char *data, size_t size, size_t nmemb, std::string *writerData);
  private:
    bool m_successfulConnection;
    CURL *m_connection;
    CURLcode m_curlCode;
    const char *m_url;
    char m_errorBuffer[CURL_ERROR_SIZE];
    std::string m_htmlContents;
};

#endif // HTTPRETRIEVER_H
