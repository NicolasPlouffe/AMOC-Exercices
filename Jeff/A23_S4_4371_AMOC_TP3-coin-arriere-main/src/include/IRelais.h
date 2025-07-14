#pragma once

class IRelais {
    public:
        virtual ~IRelais() = default;
        virtual void allumer() = 0;
        virtual void eteindre() = 0;
        virtual bool estAllume() = 0;
    
    private:
    
};