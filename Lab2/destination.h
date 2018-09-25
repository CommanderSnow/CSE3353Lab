#ifndef DESTINATION_H
#define DESTINATION_H


class destination
{
private:

    int name;
    int edge;

public:

    destination();
    destination(int);
    destination(const destination& rhs);
    destination(int x, int cost);

    void setName(int);
    const int& getName() const;

    void setEdge(int);
    const int& getEdge() const;

    friend bool operator==(destination& lhs,  destination& rhs);
    friend bool operator==(int lhs,  destination& rhs);

};

#endif // DESTINATION_H
