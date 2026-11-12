#include <iostream>
#include<cmath>
class Cylinder {
    double m_radius;
    double m_height;
    double m_volume;
public:
    Cylinder() {
        m_radius=0;
        m_height=0;
        m_volume=0;

    }
    Cylinder(double radius, double height) {
        if (radius>0) {
            m_radius=radius;
        }
        else {
            radius = 1;
        }
        if (height > 0) {
            m_height=height;
        }
        else m_height = 1;

    }
    void calcVolume() {
        m_volume = M_PI * pow(m_radius,2.0)*m_height;
    }
    double getVolume() const {
        return m_volume;
    }
    Cylinder operator+(Cylinder &rightC) {
        Cylinder temp;
        temp.m_volume=this->m_volume+rightC.m_volume;
        //temp.m_radius=this->m_radius+rightC.m_radius;
        //temp.m_height=temp.m_volume/(pow(m_radius,2.0)*M_PI);
        temp.m_height=this->m_height+rightC.m_height;
        temp.m_radius=sqrt(temp.m_volume/(temp.m_height)*M_PI);
        return temp;
    }
    friend std::ostream& operator<<(std::ostream &os, Cylinder &c);
};
std::ostream& operator<<(std::ostream &os, Cylinder &c) {
    os<<"Radius: "<<c.m_radius;
    os<<"\nHeight: "<<c.m_height;
    os<<"\nVolume: "<<c.m_volume;
    return os;
}
int main() {
    Cylinder cyli1(2.45,12.5);
    cyli1.calcVolume();
    std::cout<<cyli1.getVolume()<<" is the volume of cyli1"<<std::endl;
    Cylinder cyli2(4.85,9.125);
    cyli2.calcVolume();
    std::cout<<cyli2.getVolume()<<" is the volume of cyli2"<<std::endl;

    Cylinder cyli3 = cyli1+cyli2;//operator overloading (use case)
    std::cout<<cyli3.getVolume()<<" is the volume of cyli3"<<std::endl;
    std::cout << cyli3 << std::endl;
    return 0;
}
