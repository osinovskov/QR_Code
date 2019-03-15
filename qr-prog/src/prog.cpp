#include<iostream>
#include<qr/qr-core.hpp>
std::ostream & operator << (std::ostream & os, QR::qr_code& qrcode)
{
    std::size_t line1, line2;
    bool a, b;
    // top border
    for (std::size_t y = 0; y < 4; y += 2) {
        for (std::size_t x = 0; x < 4 + qrcode.get_width() + 4; ++x)
            os<<"\342\226\210";
        os<<'\n';
    }
    for (std::size_t y = 0; y < qrcode.get_width(); y += 2) {
        line1 =  y;
        line2 = line1 + 1;
        //left border
        for (std::size_t x = 0; x < 4; x++)
            os<<"\342\226\210";

        //qr code
        for (std::size_t x = 0; x < qrcode.get_width(); x ++) {
            a = qrcode(line1, x) ? true : false;
            b = (y+1) < qrcode.get_width() ? qrcode(line2, x) : false;
            if (a && b)
                os<<' ';
            else if (a)
                os<<"\u2584";//LOWER HALF BLOCK
            else if (b)
                os<<"\u2580";//UPPER HALF BLOCK
            else
                os<<"\342\226\210";//WHITE BLOCK
        }

        //right border
        for (std::size_t x = 0; x < 4; x++)
             os<<"\342\226\210";
         os<<'\n';
    }
    //bottom border
    for (std::size_t y = 0; y < 4; y += 2) {
       for (std::size_t x = 0; x < 4 + qrcode.get_width() + 4; ++x)
           os<<"\342\226\210";
       os<<'\n';//"\033[0m"<<'\n';
    }
    return os;
}

int main()
{
    std::string s;
    std::getline(std::cin,s);
    std::cout<<'\n';
    QR::qr_code qrcode(s.c_str());
    std::cout<<qrcode;
}
