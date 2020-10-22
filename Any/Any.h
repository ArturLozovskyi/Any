#ifndef Any_h
#define Any_h
#endif

#include "Type.h"


class Any
{
public:
    
    Any()
    {
        std::cout << "From any empty constructor" << "\n";
    };
    
    template <class T>Any(const T& data)
    {
        std::cout << "From any constructor: " << data << "\n";
        m_data = new TypeImpl<T>(data);
    };
    
    Any(const Any &any)
    {
        std::cout << "Copy constructor overloading" << "\n";
        if (any.m_data != nullptr)
        {
            m_data = any.m_data->Copy();
        }
    }

    template <class T>
    Any& operator=(const T& data)
    {
        std::cout << "Equal operator overloading" << "\n";
        delete m_data;
        m_data = new TypeImpl<T>(data);
        return *this;
    }

//    template<>
    Any& operator=(const Any& any)
    {
        // TODO: присвоение сам себе
        std::cout << "Equal Any operator overloading" << "\n";
        delete m_data;
        m_data = nullptr;
        if (any.m_data != nullptr)
        {
            m_data = any.m_data->Copy();
        }
        return *this;
    }
    
    ~Any()
    {
        delete m_data;
        std::cout << "From any destructor" << "\n";
    };
    
    template <class T> T& As ()
    {
        if (typeid(T).hash_code() != m_data->GetTypeId())
        {
            throw std::runtime_error("Can not cast\n");
        }
        return *static_cast<T*>(m_data->As());
    };
    
private:
    IType* m_data = nullptr;
};
