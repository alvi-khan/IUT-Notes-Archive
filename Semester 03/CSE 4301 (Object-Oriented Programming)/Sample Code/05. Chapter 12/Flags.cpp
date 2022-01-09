#include <bitset>
#include <iostream>
using namespace std;

void showflags();

int main()
{
    // show default condition of format flags
    showflags();

    cout.setf(ios::oct | ios::showbase | ios::fixed);

    showflags();

    return 0;
}

// This function displays the status of the format flags.
void showflags()
{
    ios::fmtflags f;

    f = cout.flags();  // get flag settings
    cout<<bitset<16>(f)<<"   fmtflag value\n";



    cout<<bitset<16>(ios::boolalpha)<<"   ";
    if(f & ios::boolalpha)
        cout << "boolalpha on\n";
    else
        cout << "boolalpha off\n";


    cout<<bitset<16>(ios::dec)<<"   ";
    if(f & ios::dec)
        cout << "dec on\n";
    else
        cout << "dec off\n";

    cout<<bitset<16>(ios::fixed)<<"   ";
    if(f & ios::fixed)
        cout << "fixed on\n";
    else
        cout << "fixed off\n";

    cout<<bitset<16>(ios::hex)<<"   ";
    if(f & ios::hex)
        cout << "hex on\n";
    else
        cout << "hex off\n";


    cout<<bitset<16>(ios::internal)<<"   ";
    if(f & ios::internal)
        cout << "internal on\n";
    else
        cout << "internal off\n";

    cout<<bitset<16>(ios::left)<<"   ";
    if(f & ios::left)
        cout << "left on\n";
    else
        cout << "left off\n";

    cout<<bitset<16>(ios::oct)<<"   ";
    if(f & ios::oct)
        cout << "oct on\n";
    else
        cout << "oct off\n";


    cout<<bitset<16>(ios::right)<<"   ";
    if(f & ios::right)
        cout << "right on\n";
    else
        cout << "right off\n";

    cout<<bitset<16>(ios::scientific)<<"   ";
    if(f & ios::scientific)
        cout << "scientific on\n";
    else
        cout << "scientific off\n";

    cout<<bitset<16>(ios::showbase)<<"   ";
    if(f & ios::showbase)
        cout << "showbase on\n";
    else
        cout << "showbase off\n";


    cout<<bitset<16>(ios::showpoint)<<"   ";
    if(f & ios::showpoint)
        cout << "showpiont on\n";
    else
        cout << "showpoint off\n";


    cout<<bitset<16>(ios::showpos)<<"   ";
    if(f & ios::showpos)
        cout << "showpos on\n";
    else
        cout << "showpos off\n";

    cout<<bitset<16>(ios::skipws)<<"   ";
    if(f & ios::skipws)
        cout << "skipws on\n";
    else
        cout << "skipws off\n";


    cout<<bitset<16>(ios::unitbuf)<<"   ";
    if(f & ios::unitbuf)
        cout << "unitbuf on\n";
    else
        cout << "unitbuf off\n";

    cout<<bitset<16>(ios::uppercase)<<"   ";
    if(f & ios::uppercase)
        cout << "uppercase on\n";
    else
        cout << "uppercase off\n";


    cout << "\n";
}
