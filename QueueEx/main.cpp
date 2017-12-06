#include <iostream>
#include <cstring>

using namespace std;

const size_t MAXSIZE=255;
enum STATUS{SUCCESS, STACKOVERFLOW, NOELEMENT};

template <class T>

class queueEx{
public:
    queueEx();
    ~queueEx();
    STATUS push(T newelm);
    STATUS pop();
    T top();
    size_t size();

private:
    size_t nsize;
    T elem[MAXSIZE];
};

template <class T>
queueEx<T>::queueEx()
{
    nsize = 0;
}

template <class T>
queueEx<T>::~queueEx()
{
    nsize = 0;
}

template <class T>
STATUS queueEx<T>::push(T newelm) {
    if(nsize == MAXSIZE) return STACKOVERFLOW;
    elem[nsize] = newelm;
    nsize++;
    return SUCCESS;
}

template <class T>
STATUS queueEx<T>::pop(){
    if(nsize == 0) return NOELEMENT;
    nsize--;
    return SUCCESS;
}

template <class T>
T queueEx<T>::top() {
    if(nsize == 0) return NOELEMENT;
    return elem[nsize-1];
}

template <class T>
size_t queueEx<T>::size(){
    return nsize;
}

int main() {
    queueEx<int> a;
    a.push(10);
    a.push(11);
    cout << "size=" << a.size() <<endl;
    cout << "top=" << a.top() << endl;
    a.pop();
    cout << "size=" << a.size() <<endl;
    cout << "top=" << a.top() << endl;
    a.pop();
    cout << "size=" << a.size() <<endl;
    cout << "top=" << a.top() << endl;
    return 0;
}