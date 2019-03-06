#ifndef VEC_H
#define VEC_H

class Vec {

  public:
    double x, y, z;

    Vec();
    Vec(double);
    Vec(double, double, double);

    double length() const;
    void normalize();
    double dot( Vec ) const;
    double angle( Vec ) const;

};

#endif /* !VEC_H */
