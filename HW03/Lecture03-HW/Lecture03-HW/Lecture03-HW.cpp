#include <iostream>
#include <string>
#include <bitset>
#include <stdio.h>



using namespace std;

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};



int main()
{
    int n = 10;
    int x = 0;
    int y = 0;
    cout << "화면에 그림을 그리는 프로그램 입니다.\n";
    cout << "학번 : 202127027\n";
    cout << "이름 : 김중석\n";

    const string RESET = "\033[0m";

    while (x <= 63)
    {

        cout << " 화면에 그릴 블럭의 색깔 코드를 입력하세요(1~63/64입력시 종료) : ";

        cout << "2진수 변환 테스트 숫자를 입력하세요 : ";
        cin >> x;
        string binary = bitset<8>(x).to_string();
        if (binary == "00000001")//1
        {
            cout << "\x1b[037m" << "하얀색!\n" << RESET;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == 1 || i == n || j == 1 || j == n) cout << "\x1b[037m" << "*" << RESET;
                    else cout << " ";
                }
                cout << "\n";
            }
        }
        else if (binary == "00000010")//2
        {
            cout << "\x1b[031m" << "빨간색!\n" << RESET;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == 1 || i == n || j == 1 || j == n) cout << "\x1b[031m" << "*" << RESET;
                    else cout << " ";
                }
                cout << "\n";
            }
        }
        else if (binary == "00000100")//4
        {
            cout << "\x1b[032m" << "초록색!\n" << RESET;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == 1 || i == n || j == 1 || j == n) cout << "\x1b[032m" << "*" << RESET;
                    else cout << " ";
                }
                cout << "\n";
            }
        }
        else if (binary == "00001000")//8
        {
            cout << "\x1b[033m" << "노란색!\n" << RESET;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == 1 || i == n || j == 1 || j == n) cout << "\x1b[033m" << "*" << RESET;
                    else cout << " ";
                }
                cout << "\n";
            }
        }
        else if (binary == "00010000")//16
        {
            cout << "\x1b[036m" << "청록색!\n" << RESET;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == 1 || i == n || j == 1 || j == n) cout << "\x1b[036m" << "*" << RESET;
                    else cout << " ";
                }
                cout << "\n";
            }
        }
        else if (binary == "00100000")//32
        {
            cout << "\x1b[035m" << "마젠타색!\n" << RESET;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == 1 || i == n || j == 1 || j == n) cout << "\x1b[035m" << "*" << RESET;
                    else cout << " ";
                }
                cout << "\n";
            }
        }
    }







    return 0;

    /*cout << "\x1b[033m" << "아름다운 색!! 우왕";*/
    /*
    * 흰색 블록을 그리는 키코드 : 1 (1)
    * 빨강색 블록을 그리는 키코드 : 2 (10)
    * 녹색 블록을 그리는 키코드 : 4 (100)
    * 노란색 블록을 그리는 키코드 : 8 (1000)
    * 청록색 블록을 그리는 키코드 : 16 (10000)
    * 마젠타색 블록을 그리는 키코드 : 32 (100000)
    * 프로그램 종료 : 64 (1000000)
    *
    * 프로그램을 시작하면 아래와 같이 쓰시오
    *
    *
    * 화면에 그림을 그리는 프로그램입니다.
    * 학번 : 349218347(본인학번)
    * 이름 : 본인이름
    *
    * 화면에 그릴 물체코드를 입력하세요 :
    * (반복)
    */

}



