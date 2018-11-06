#ifndef POINT_H
#define POINT_H


class point
{
private:

    int name;
    float x;
    float y;
    float z;

public:

    point();
    point(int, float, float, float);
    point(const point&);

    //getters and setters
    const int &getCName() const;
    int &getName();
    float& getX();
    float& getY();
    float& getZ();

    void getLocation(float* &);

    void setName(int);
    void setX(float);
    void setY(float);
    void setZ(float);


    friend bool operator<(const point &lhs, const point &rhs);


};

#endif // POINT_H
