#define _CRT_SECURE_NO_WARNINGS
#include "all.h"

int main(void)
{
    try {
        time_t now = time(nullptr);
        const tm* nowlt = localtime(&now);

        stringstream x;
        x << "R0";
        x << nowlt->tm_year - 118;
        x << ".";
        x << nowlt->tm_mon + 1;
        x << ".";
        x << nowlt->tm_mday;

        string result_r = x.str();

        stringstream y;
        y << "令和";
        y << nowlt->tm_year - 118;
        y << "年";
        y << nowlt->tm_mon + 1;
        y << "月";
        y << nowlt->tm_mday;
        y << "日";

        string result_reiwa = y.str();

        // OneYear → 365 days.
        int OneYear_Days = 365;

        int redays = nowlt->tm_yday;
        int redays_mini = OneYear_Days - redays;

        string tim = "時刻を表示";
        string gantan = "来年の1月1日まであと";
        string aisatu = " 日です";
        string number = "日めくり数え番号";
        string week = "曜日";

        // week Sun ~ Sat
        time_t timer;
        struct tm* t_st;
        const char* wday[] = { "日", "月", "火", "水", "木", "金", "土" };

        // Month 和風月
        const char* wmonth[] = { "睦月", "如月", "弥生", "卯月", "皐月", "水無月", "文月", "葉月", "長月", "神無月", "霜月", "師走"
        };

        time(&timer);
        t_st = localtime(&timer);

        stringstream ss;
        stringstream ssd;

        // version number
        ss << 1;
        ssd << 1;
        string str_num = ss.str();
        string str_dd = ssd.str();
        string comma = " : ";

        // version number comma
        string number_comma = ".1.";

        string himekuri = number + comma + str_num + number_comma + str_dd;

        const date today = day_clock::local_day();

        auto facet = new time_facet("%Y年%m月%d日 : %H時%M分%S秒");
        ss.imbue(locale(cout.getloc(), facet));
        auto now_time = second_clock::local_time();
        ss << now_time;
        auto str_rep = (ss.str()).replace(0,1, "");

        if (gregorian_calendar::is_leap_year(today.year())) {
            cout << "今年はうるう年" << comma << today.year() << "年です!" << endl;
        }
        else {
            cout << tim << comma << str_rep << comma << wday[t_st->tm_wday] << week << comma << wmonth[t_st->tm_mon] << endl;
            cout << gantan << comma << redays_mini << aisatu << endl;
            cout << result_reiwa << comma << result_r << endl;
            cout << himekuri << endl;
        }

        // C++ version info.
        int cpp20 = 202002;
        int cpp17 = 201703;
        int cpp14 = 201402;
        int cpp11 = 201103;
        int cpp98 = 199711;

        // int type → string type changes.
        string cpp_ver = to_string(_MSVC_LANG);

        if (cpp_ver.compare(to_string(cpp20)) == 0)
            cout << "現在の C++ : C++20" << endl;
        else if (cpp_ver.compare(to_string(cpp17)) == 0)
            cout << "現在の C++ : C++17" << endl;
        else if (cpp_ver.compare(to_string(cpp14)) == 0)
            cout << "現在の C++ : C++14" << endl;
        else if (cpp_ver.compare(to_string(cpp11)) == 0)
            cout << "現在の C++ : C++11" << endl;
        else if (cpp_ver.compare(to_string(cpp98)) == 0)
            cout << "現在の C++ : C++98" << endl;
        else
            cout << "現在の C++ : pre-standard C++" << endl;

    } catch (runtime_error& e) {
        cout << "caught exception : " << e.what() << endl;
    }
    quick_exit(0);
}
