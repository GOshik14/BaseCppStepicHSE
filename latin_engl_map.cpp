/*************************************************************************************
Однажды, разбирая старые книги на чердаке, школьник Вася нашёл англо-латинский словарь.
 Английский он к тому времени знал в совершенстве, и его мечтой было изучить латынь.
 Поэтому попавшийся словарь был как раз кстати.

К сожалению, для полноценного изучения языка недостаточно только одного словаря:
 кроме англо-латинского необходим латинско-английский. За неимением лучшего он
 решил сделать второй словарь из первого.

Как известно, словарь состоит из переводимых слов, к каждому из которых приводится
 несколько слов-переводов. Для каждого латинского слова, встречающегося где-либо в словаре,
 Вася предлагает найти все его переводы (то есть все английские слова,
 для которых наше латинское встречалось в его списке переводов),
 и считать их и только их переводами этого латинского слова.

Помогите Васе выполнить работу по созданию латинско-английского словаря из англо-латинского.
***************************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include  <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    //map<string, vector<string>> en_lat;
    map<string, vector<string>> lat_en;

    size_t n;
    cin >> n >> ws;

    for (size_t i = 0; i < n; i++)
    {
        string en_w, tmp_s;
        vector<string> tmp_v;
        cin >> en_w >> ws >> tmp_s >> ws;
        getline(cin, tmp_s);


        size_t first = 0;
        size_t second = tmp_s.find(',');
        while(second != string::npos)
        {
            tmp_v.push_back(tmp_s.substr(first, second - first));
            first = second + 2;
            second = tmp_s.find(',', first);
        }
        tmp_v.push_back(tmp_s.substr(first));

 
        for(const auto &str : tmp_v)
        {
            if(lat_en.find(str) == lat_en.end())
            {
                lat_en[str] = {en_w};
            }
            else
            {
                lat_en[str].push_back(en_w);
            }
        }
        
    }
    

    cout << lat_en.size() << endl;

    for (const auto &el : lat_en)
    {
        string ans;

        ans += el.first;
        ans += " - ";

        for (const auto &str : el.second)
        {
            ans += str + ", ";
        }
        ans.pop_back();
        ans.pop_back();

        cout << ans << endl;
        
    }
    


    return 0;
}