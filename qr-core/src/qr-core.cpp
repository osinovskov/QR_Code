#include<qr/qr-core.hpp>
#include<cassert>
#include<utility>

namespace QR {
    qr_code::qr_code(const char* string)
    {
        qr = QRcode_encodeString(string,0,QR_ECLEVEL_L,QR_MODE_8,1);
    }

    qr_code::~qr_code()
    {
        QRcode_free(qr);
    }

    // Только перемещаемый, не копируемый класс
    qr_code::qr_code(qr_code&& other)
        :qr(std::exchange(other.qr,nullptr))
    {}

    //Pаботает только как перемещение
    qr_code& qr_code::operator=(qr_code other)
    {
        swap(*this,other);
        return *this;
    }

    bool qr_code::operator()(std::size_t i, std::size_t j) const
    {
        assert((i<qr->width) && (j<qr->width));
        return (((qr->data[i*qr->width + j])%2));
    }
}
