#ifndef TEORICO_H
#define TEORICO_H

class Teorico
{
private:
    int cantAsistentes;
public:
    Teorico();
    ~Teorico();
    int getCantAsistentes() const;
    void setCantAsistentes(int);
};

#endif
