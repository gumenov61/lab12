#include <iostream>
#include <curl/curl.h>

using namespace std;

int main(int argc, char* argv[]) {
    
    CURL *curl = curl_easy_init();
    CURLcode res;

    if(curl) {

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_NOBODY, true);
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.yandex.ru");
        
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {

            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            cout << "\'www.yandex.ru\' >> RESPONSE CODE >> " << response_code << endl;

        } else {
            cout << "ERROR:\t" << curl_easy_strerror(res) << endl;
        }
        
        curl_easy_cleanup(curl);
    }

    return 0;
}