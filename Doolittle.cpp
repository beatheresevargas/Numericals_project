#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double a11, a12, a13, a21, a22, a23, a31, a32, a33;
    double C1, C2, C3, R1, R2, R3, x1, x2, x3;
    double U11, U12, U13, L21, L31, U22, U23, L32, U33;

    cout << "DOOLITTLE'S METHOD" << endl << endl;

    cout << "Enter value for a11: ";
    cin >> a11;
    cout << "Enter value for a12: ";
    cin >> a12;
    cout << "Enter value for a13: ";
    cin >> a13;
    cout << "Enter value for a21: ";
    cin >> a21;
    cout << "Enter value for a22: ";
    cin >> a22;
    cout << "Enter value for a23: ";
    cin >> a23;
    cout << "Enter value for a31: ";
    cin >> a31;
    cout << "Enter value for a32: ";
    cin >> a32;
    cout << "Enter value for a33: ";
    cin >> a33;
    cout << "Enter value for C1: ";
    cin >> C1;
    cout << "Enter value for C2: ";
    cin >> C2;
    cout << "Enter value for C3: ";
    cin >> C3;

    cout << endl;

    cout << "Entered values: " << endl << "a11 = " << a11 << "  a12 = " << a12 << "  a13 = " << a13 << endl
                                        << "a21 = " << a21 << "  a22 = " << a22 << "  a23 = " << a23 << endl
                                        << "a31 = " << a31 << "  a32 = " << a32 << "  a33 = " << a33 << endl
                                        << "C1 = " << C1 << "  C2 = " << C2 << "  C3 = " << C3 << endl << endl;

    U11 = a11;
    U12 = a12;
    U13 = a13;
    L21 = a21/a11;
    L31 = a31/a11;
    U22 = a22-(L21*U12);
    U23 = a23-(L21*U13);
    L32 = (a32-(L31*U12))/U22;
    U33 = a33-(L31*U13)-(L32*U23);

    cout << "Values for [U]" << endl;
    cout << "U11 = " << a11 << endl << "U12 = " << a12 << endl << "U13 = " << a13 << endl << "U22 = " << U22 << endl << "U23 = " << U23 << endl << "U33 = " << U33 << endl;

    cout << endl;

    cout << "Values for [L]" << endl;
    cout << "L21 = " << L21 << endl << "L31 = " << L31 << endl << "L32 = " << L32 << endl;

    cout << endl;

    cout << "EQUATIONS IN TERMS OF R: " << endl;
    cout << "(1*R1) + (0*R2) + (0*R3) = " << C1 << endl
            << "(" << L21 << "*R1) + (1*R2) + (0*R3) = " << C2 << endl
            << "(" << L31 << "*R1) + (" << L32 << "*R2) + (1*R3) = " << C3 << endl;

    cout << endl;

    cout << "SOLVE FOR R: " << endl;

    R1 = C1;

    if (L21 >= 0)
    {
        R2 = C2-(L21*R1);
    }
    else
    {
        R2 = C2+(L21*R1);
    }

    if (L31 >= 0 |& L32 >= 0)
    {
        R3 = C3-(L31*R1)-(L32*R2);
    }
    else
    {
        R3 = C3+(L31*R1)+(L32*R2);
    }

    cout << "R1 = " << R1 << endl << "R2 = " << R2 << endl << "R3 = " << R3 << endl << endl;

    cout << "EQUATIONS IN TERMS OF x: " << endl;

    cout << "(" << U11 << "*x1) + (" << U12 << "*x2) + (" << U13 << "*x3) = " << R1 << endl <<
            "(0*x1) + (" << U22 << "*x2) + (" << U23 << "*x3) = " << R2 << endl <<
            "(0*x1) + (0*x2) + (" << U33 << "*x3) = " << R3 << endl << endl;

    cout << "SOLVE FOR x: " << endl;

    x3 = R3/U33;

    if (U23 >= 0)
    {
        x2 = (R2-(U23*x3))/U22;
    }
    else
    {
        x2 = (R2+(U23*x3))/U22;
    }

    if (U12 >= 0 |& U13 >= 0)
    {
        x1 = (R1-(U12*x2)-(U13*x3))/U11;
    }
    else
    {
        x1 = (R1+(U12*x2)+(U13*x3))/U11;
    }

    cout << "x3 = " << x3 << endl << "x2 = " << x2 << endl << "x1 = " << x1 << endl;
    return 0;
}
