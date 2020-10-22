#ifndef Type_h
#define Type_h
#include <iostream>

// (1234567890) 123
// type         typeimpl
//
// pointer virtual table
// why virtual destructor, virtual constructor, virtual function



//IType* ABC = new TypeImpl<int>;
//IType* ABC1 = new TypeImpl<int>;
//IType* ABC2 = new TypeImpl<int>;


class IType
{
public:
    
    virtual ~IType() = 0;
    virtual void* As() const = 0;
    virtual size_t GetTypeId() const = 0;
    virtual IType* Copy() const = 0;
};

IType::~IType () {
    std::cout << "Type destructor" << "\n";
}

template<typename T> class TypeImpl : public IType
{
public:
    
    void* As() const override { return m_data; };
    
    TypeImpl(const T& data) {
        m_data = new T(data);
    };
    
    IType * Copy() const override
    {
        return new TypeImpl<T>(*m_data);
    }
    
    size_t GetTypeId() const override
    {
        return typeid(T).hash_code();
    }
    
    ~TypeImpl()
    {
        delete m_data;
        std::cout << "TypeImpl destructor" << "\n";
    };

private:
    T* m_data = nullptr;
};
#endif
