#include "Spanzura.h"
#include <iostream>

using std::cout;
Spanzura::Spanzura()
{
    //ctor
}

Spanzura::~Spanzura()
{
    //dtor
}
void Spanzura::afiseaza_span(int nr_greseli)
{
    if( nr_greseli==0)
    {
        cout<<"##############################\n"
            "#   #                        #\n"
            "#  #                         #\n"
            "# #                           \n"
            "#                             \n"
            "#                             \n"
            "#                             \n"
            "#                             \n"
            "#                             \n"
            "#                             \n"
            "###########                   \n";
    }

    if( nr_greseli==1)

    {
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                           \n"
            "#                           \n"
            "#                           \n"
            "#                           \n"
            "###########                 \n";
    }


 if( nr_greseli==2)

    {
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                          #  \n"
            "#                          # \n"
            "#                          #  \n"
            "#                           \n"
            "###########                 \n";
    }

if( nr_greseli==3)

    {
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                          #  \n"
            "#                          # \n"
            "#                          #  \n"
            "#                        #   \n"
            "###########             #    \n";
    }

if( nr_greseli==4)

    {
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                          #  \n"
            "#                          # \n"
            "#                          #  \n"
            "#                        #   #\n"
            "###########             #     #\n";
    }

if( nr_greseli==5)

    {
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                      #   #  \n"
            "#                        # # \n"
            "#                          #  \n"
            "#                        #   #\n"
            "###########             #     #\n";
    }


if( nr_greseli==6)

    {
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                      #   #   #\n"
            "#                        # # #\n"
            "#                          #  \n"
            "#                        #   #\n"
            "#                       #     #\n"
            "#                               \n"
            "#                                \n"
            "###########                       \n";
    }

if (nr_greseli==7)
{
 cout<<"__     __           _ \n";
 cout<<"\ \   / /          | |  \n";
 cout<<" \ \_/ /__  _   _  | | ___  ___  ___  \n";
 cout<<"  \   / _ \| | | | | |/ _ \/ __|/ _ \  \n";
 cout<<"   | | (_) | |_| | | | (_) \__ \  __/   \n";
 cout<<"   |_|\___/ \__,_| |_|\___/|___/\___|    \n";


    exit(0);
}
}