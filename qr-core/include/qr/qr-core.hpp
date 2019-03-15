#ifndef QR_CORE_HPP
#define QR_CORE_HPP
#include <cstddef>
#include<qrencode.h>
namespace QR {
    class qr_code
    {
    private:
        QRcode* qr;
    public:
        qr_code(const char* string);
        ~qr_code();
        friend void swap(qr_code& qrc1,qr_code& qrc2) {std::swap(qrc1.qr,qrc2.qr);}
        qr_code(qr_code&& other);
        qr_code& operator=(qr_code other);
        bool operator()(std::size_t i, std::size_t j) const;
        std::size_t get_width() const {return qr->width;}
    };
}
#endif
