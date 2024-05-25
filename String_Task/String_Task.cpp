// String_Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

string addition(string a, string b);
string substruction(string a, string b);
string multiplection(string a, string b);
string dividation(string a, string b);
bool is_greater(string a, string b);
bool is_correct_input(string num);
size_t get_rid_of_dot(string& num);

bool is_greater(string a, string b)
{
    bool minus = false;
    if (b[0] == *"-")
    {
        if (a[0] == *"-")
        {

            a.erase(0, 1);
            b.erase(0, 1);

            minus = true;
        }
        else
        {
            
            return true;
        }
    }
    else if (a[0] == *"-")
    {
        
        return true;
    }
    if (a.length() < b.length())
    {
        return false + minus;
    }
    if (a.length() > b.length())
    {
        return true - minus;
    }
    for (int i = 0; i< a.length(); i++)
    {
        if (a[i] < b[i])
        {
            return false + minus;
        }
        if (a[i] > b[i])
        {
            return true - minus;
        }
    }

    
}
bool have_dot(string num) //есть ли дробная часть
{
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == *".")
        {
            return true;
        }
    }
    return false;
}
void add_zeroes(string& num, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        num.push_back('0');
    }
}

size_t get_rid_of_dot(string& num) // убирает точку из числа и возвращает число цифр после нее. должна быть всегда после проверки на наличие точки
{   
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '.')
        {
           num.erase(i, 1);
           return num.length() - i;
        }
    }
}

bool is_correct_input(string num) // проверяет корректность вводимых чисел
{
    short dot_count = 0;
    if (num == "")
    {
        throw "Blank input";
        return false;
    }
    if(num[0] == '.')
    {
        throw "Dot is not ment to be first";
        return false;
    }
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] < 48 or num[i] > 57)
        {
            if (!(num[i] == '.') or (i > 0 and num[i] == '-'))
            {
                throw "Incorrect symbol";
                return false;
            }  
            if(num[i] == '.')
            {
                dot_count++;
            }
            if (dot_count == 2)
            {
                throw "To many dots in number";
                return false;
            }

            
        }
    }
    return true;
}
string dividation(string a, string b) // деление
{
    if (!is_correct_input(a) or !is_correct_input(b))
    {
        return "0";
    }
    if (a == "0")
    {
       
        return "0";
    }
    if (b == "0")
    {
        throw "You can nod divide by zero";
        return "0";
    }
    bool minus = false;
    if (a[0] == *"-")
    {
        if (b[0] == *"-")
        {

            a.erase(0, 1);
            b.erase(0, 1);
        }
        else
        {
            a.erase(0);
            minus = true;
        }
    }
    if (b[0] == *"-")
    {
        b.erase(0, 1);
        minus = true;
    }

    size_t after_dot_a = 0;
    size_t after_dot_b = 0;
    string res = "0";
    string temp_znam;
    char temp_del;
    string temp_sum;
    char ad = *"0";

    if (have_dot(a))
    {


        if (have_dot(b))
        {
            after_dot_a = get_rid_of_dot(a);
            after_dot_b = get_rid_of_dot(b);
            if (after_dot_a > after_dot_b)
            {
                add_zeroes(b, after_dot_a - after_dot_b);
            }
            if (after_dot_a < after_dot_b)
            {
                add_zeroes(a, after_dot_b - after_dot_a);
            }

        }
        else
        {
            after_dot_a = get_rid_of_dot(a);
            add_zeroes(b, after_dot_a);
        }

    }
    while (is_greater(a, b))
    {
        temp_znam = a.front();
        a.erase(0, 1);
        
        while (!is_greater(temp_znam,b))
        {
            temp_znam += a.front();
            a.erase(0, 1);
        }

        while (is_greater(temp_znam, b))
        {
            temp_znam = substruction(temp_znam, b);
            ad++;
        }
        a = temp_znam + a;
        res += ad;
        ad = *"0";

    }
    res += ".";
    int add_len = 6;
    
    while((add_len > 0) and (a != "0"))
    {
        temp_znam = a.front();
        a.erase(0, 1);

        while (!is_greater(temp_znam, b))
        {
            if(a.length())
            {
                temp_znam += a.front();
                a.erase(0, 1);
            }
            else
            {
                temp_znam += "0";
            }
        }

        while (is_greater(temp_znam, b))
        {
            temp_znam = substruction(temp_znam, b);
            ad++;
        }
        a = temp_znam + a;
        res += ad;
        ad = *"0";
        add_len--;
    }
    while (res.front() == *"0")
    {
        res.erase(0, 1);
    }

    if (minus)
    {
        res = "-" + res;
    }
    return res;
    
}
string multiplection(string a, string b) // умножение
{
    if (!is_correct_input(a) or !is_correct_input(b))
    {
        return "0";
    }
    if (a == "0")
    {
        return 0;
    }
    if (b == "0")
    {
        return 0;
    }
    bool minus = false;
    if (a[0] == *"-")
    {
        if (b[0] == *"-")
        {

            a.erase(0, 1);
            b.erase(0, 1);
        }
        else
        {
            a.erase(0);
            minus = true;
        }
    }
    
    string res = "0";
    char temp_a;
    char temp_b;
    string temp_sum;
    string ad = "";
    size_t after_dot_a = 0;
    size_t after_dot_b = 0;


    if (have_dot(a))
    {


        if (have_dot(b))
        {
            after_dot_a = get_rid_of_dot(a);
            after_dot_b = get_rid_of_dot(b);
        }
        else
        {
            after_dot_a = get_rid_of_dot(a);
        }

    }
    else if (have_dot(b))
    {
        after_dot_a = get_rid_of_dot(b);
    }

    if (a.length() < b.length())
    {
        auto tem = a;
        a = b;
        b = tem;
    }

    while (b.length() > 0)
    {
        
        temp_b = b.back();
       
        b.pop_back();

        
        
        temp_b -= 48;
        temp_sum = "0";
        while (temp_b > 0)
        {
            temp_sum = addition(temp_sum, a);
            temp_b -= 1;
        }
        res = addition(res,temp_sum + ad);
        ad += "0";
    }

    if (after_dot_a != 0)
    {
        res.insert(res.length() - (after_dot_a + after_dot_b), ".");
    }
    if(minus)
    {
        res = "-" + res;
    }
    

    return res;
}
string substruction(string a, string b) // вычитание
{
    if (!is_correct_input(a) or !is_correct_input(b))
    {
        return "0";
    }
    bool minus = false;
    if (b[0] == *"-")
    {
        if (a[0] == *"-")
        {

            a.erase(0, 1);
            b.erase(0, 1);

            minus = true;
        }
        else
        {
            b.erase(0);
            return addition(a, b);
        }
    }
    else if (a[0] == *"-")
    {
        a.erase(0);
        return addition(a, b);
    }

    if(a == "0")
    {
        return b;
    }
    if (b == "0")
    {
        return a;
    }

    size_t after_dot_a = 0;
    size_t after_dot_b = 0;
    string res = "";
    char temp_a;
    char temp_b;
    char temp_sum;
    char ad = *"0";

    if (have_dot(a))
    {


        if (have_dot(b))
        {
            after_dot_a = get_rid_of_dot(a);
            after_dot_b = get_rid_of_dot(b);
            if (after_dot_a > after_dot_b)
            {
                add_zeroes(b, after_dot_a - after_dot_b);
            }
            if (after_dot_a < after_dot_b)
            {
                add_zeroes(a, after_dot_b - after_dot_a);
            }

        }
        else
        {
            after_dot_a = get_rid_of_dot(a);
            add_zeroes(b, after_dot_a);
        }

    }
    else if (have_dot(b))
    {
        after_dot_a = get_rid_of_dot(b);
        add_zeroes(a, after_dot_a);
    }

    if ((a.length() < b.length()) or (!is_greater(a, b)))
    {
        auto tem = a;
        a = b;
        b = tem;
        minus = !minus;
    }
    while (b.length() > 0)
    {
        temp_a = a.back();
        temp_b = b.back();
        a.pop_back();
        b.pop_back();
        temp_sum = temp_a - temp_b - ad + 48;
        ad = *"0";
        if (temp_sum < 0)
        {
            ad = *"1";
            temp_sum = 10 + temp_sum;
        }
        res.push_back(temp_sum + 48);
    }

    if (a.length() > 0)
    {
        while (a.length() > 0)
        {
            temp_a = a.back();
            a.pop_back();

            temp_sum = temp_a - ad;
            ad = *"0";
            if (temp_sum < 0)
            {
                ad = *"1";
                temp_sum = 10 + temp_sum;
            }
            res.push_back(temp_sum + 48);

        }
    }

    if (ad != *"0")
    {
        res.push_back(*"1");
    }
    while(res.back() == *"0")
    {
        res.pop_back();
    }

    if (minus == true)
    {
        res.push_back(*"-");
    }
    if (after_dot_a != 0)
    {
        res.insert(after_dot_a, ".");
    }
    reverse(res.begin(), res.end());

    return res;





    return "";
}
string addition(string a, string b) // сложение
{

    if (!is_correct_input(a) or !is_correct_input(b))
    {
        return "0";
    }

    bool minus = false;
    if (a == "0")
    {
        return b;
    }
    if (b == "0")
    {
        return a;
    }

    if (a[0] == *"-")
    {
        if (b[0] == *"-")
        {
            
            a.erase(0,1);
            b.erase(0,1);
           
            minus = true;
        }
        else
        {
            a.erase(0);
            return substruction(a, b);
        }
    }
    else if (b[0] == *"-")
    {
        b.erase(0);
        return substruction(a, b);
    }

   



    size_t after_dot_a = 0;
    size_t after_dot_b = 0;
    string res = "";
    char temp_a;
    char temp_b;
    char temp_sum;
    char ad = '0';


    if(have_dot(a))
    {

       
        if (have_dot(b))
        {
            after_dot_a = get_rid_of_dot(a);
            after_dot_b = get_rid_of_dot(b);
            if(after_dot_a > after_dot_b)
            {
                add_zeroes(b, after_dot_a - after_dot_b);
            }
            if (after_dot_a < after_dot_b)
            {
                add_zeroes(a, after_dot_b - after_dot_a);
            }
           
        }
        else
        {
            after_dot_a = get_rid_of_dot(a);
            add_zeroes(b, after_dot_a);
        }
        
    }
    else if (have_dot(b))
    {
        after_dot_a = get_rid_of_dot(b);
        add_zeroes(a, after_dot_a);
    }



    

    if (a.length() < b.length())
    {
        auto tem = a;
        a = b;
        b = tem;
    }
    while (b.length() > 0)
    {
        temp_a = a.back();
        temp_b = b.back();
        a.pop_back();
        b.pop_back();
        temp_sum = temp_a + temp_b + ad - 144;
        ad = *"0";
        if(temp_sum >= 10)
        {
            ad = *"1";
            temp_sum -= 10;
        }
        res.push_back(temp_sum + 48);
    }

    if (a.length() > 0)
    {
        while (a.length() > 0)
        {
            temp_a = a.back();
            a.pop_back();
            
            temp_sum = temp_a + ad - 96;
            ad = *"0";
            if (temp_sum >= 10)
            {
                ad = *"1";
                temp_sum -= 10;
            }
            res.push_back(temp_sum + 48);

        }
    }

    if (ad != *"0")
    {
       res.push_back(*"1");
    }
    if (minus == true)
    {
      res.push_back(*"-");
    }
    if(after_dot_a != 0)
    {
        res.insert(after_dot_a, ".");
    }
    reverse(res.begin(), res.end());

    return res;
}


int main()
{
    try
    {
        string a, b;
        a = "12";
        b = "123";
        cout << addition(a, b) << "\n";

        a = "12.46564";
        b = "123.23423";
        cout << addition(a, b) << "\n";

        a = "55";
        b = "121";
        cout << substruction(a, b) << "\n";

        a = "5.4";
        b = "1.5";
        cout << substruction(a, b) << "\n";

        a = "1169";
        b = "1621";
        cout << multiplection(a, b) << "\n";

        a = "116.0";
        b = "1121.56";
        cout << multiplection(a, b) << "\n";

        a = "100.7";
        b = "6.5";
        cout << dividation(a, b) << "\n";

        a = "1005";
        b = "321";
        cout << dividation(a, b) << "\n";

        a = "--100.1";
        b = "6.6adsad";
        cout << addition(a, b) << "\n";
    }
    catch(const char* error_message)
    {
        cout << error_message << "\n";
    }
}
