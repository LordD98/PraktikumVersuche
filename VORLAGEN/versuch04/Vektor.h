//
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef Vektor_H
#define Vektor_H

#define PI 3.141592653589793238
#define DIM 3

class Vektor
{
   public:
    Vektor(double x, double y, double z);
    ~Vektor();

    double getX() const;
    double getY() const;
    double getZ() const;
      
    Vektor sub(const Vektor& input) const;
    Vektor add(const Vektor& input) const;
    
    double length() const;
    bool ortho(const Vektor& input) const;
    double scalarProd(const Vektor& input) const;
    double angle(const Vektor& input) const;
    
    void rotateAroundZ(const double rad);
    
    void ausgabe() const;

	void transformWithMatrix(const double transformationMatrix[DIM][DIM]);

   private:
    double x;
    double y;
    double z;
	double rotationMatrix[DIM][DIM] = { {0,0,0},{0,0,0},{0,0,0} };

};

#endif
