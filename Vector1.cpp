#include "Vector1.h"
Vector::Vector(int n, int t)
{
    this->n = n;
    this->p = new int[this->n];
    for (int i = 0; i < this->n; i++)
    {
        *(this->p + i) = t;
    }
}
Vector::~Vector()
{
    delete[] this->p;
}
ostream &operator<<(ostream &o, Vector &v)
{
    for (int i = 0; i < v.n; i++)
    {
        o << v[i] << "\t";
    }
    o << "\n";
    return o;
}
int &Vector::operator[](const int &i)
{
    static int data = -1;
    if (i >= 0 && i < n)
        return *(this->p + i);
    else
        return data;
}
Vector::Vector(const Vector &v)
{
    this->n = v.n;
    this->p = new int[this->n];
    for (int i = 0; i < this->n; i++)
    {
        (*this)[i] = *(v.p + i);
    }
}
const Vector &Vector::operator=(const Vector &v)
{
    if (this != &v)
    {
        this->n = v.n;
        this->p = new int[this->n];
        for (int i = 0; i < this->n; i++)
        {
            (*this)[i] = *(v.p + i);
        }
    }
    return *this;
}
Vector operator+(const Vector& v1,const Vector &v2)
{
    Vector v;
    //if(v1.n!=v2.n) return 0;
    for (int i = 0; i <v1.n; i++)
    {
        *(v.p+i)=*(v1.p+i)+*(v2.p+i);
    }
    return v;
}
void Vector::Show()
{   
    
    for (int i = 0; i < this->n; i++)
    {
        cout << *(this->p + i) << " ";                       
    }
}