
/*#include <iostream>
#include "Lista.h"
#include "Operacion.h"
#include "Marquesina.h"
#include <thread>
#include "Menu.h"
using namespace std;
int main()
{
    menu_inicio();
}
*/


#pragma comment (lib,"libmat.lib")
#pragma comment (lib,"libmx.lib")
#pragma comment (lib, "libmex.lib ")
#pragma comment(lib,"libeng.lib")

#include <engine.h>
#include <math.h>
#include <stdio.h>
#include <vcruntime_string.h>
#include <iostream>
using namespace std;

//int graficaMatlab(int tiempo) {
//    Engine* ep;
//    mxArray* T = NULL, * result = NULL, * R = NULL;
//    char buffer[BUFSIZ + 1];
//    double time[10] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
//
//    //Abrimos matlab
//    if (!(ep = engOpen(""))) {
//        fprintf(stderr, "\nCan't start MATLAB engine\n");
//        return EXIT_FAILURE;
//    }
//
//    //Creamos la variables
//    T = mxCreateDoubleMatrix(1, 10, mxREAL);
//    memcpy((void*)mxGetPr(T), (void*)time, sizeof(time));
//    R = mxCreateDoubleMatrix(1, 1, mxREAL);
//    memcpy((void*)mxGetPr(R), (void*)time, sizeof(1));
//
//    //Evaluamos las funciones
//
//    engEvalString(ep, "D = T.^2;");
//    engEvalString(ep, "P = R;");
//    engEvalString(ep, "F = P.^2;");
//
//    //Grafica de resultados
//    engEvalString(ep,"tiempo");
//    void matlab(int tiempo); {
//        Engine* m_pEngine;
//        m_pEngine = engOpen("null");
//        const int arraysize = 1000;
//        const double detorad = .0174;
//        double SinArray[arraysize];
//        double CosArray[arraysize];
//        double Degrees[arraysize];
//        for (int i = 0; i < arraysize; i++) {
//            Degrees[i] = i;
//            SinArray[i] = sin(i * detorad);
//            CosArray[i] = cos(i * detorad);
//        }
//        cout << "Digite " << endl;
//        char Sim = '1';
//        cin >> Sim;
//
//        if (Sim == '1') {
//            mxArray* SIN = mxCreateDoubleMatrix(arraysize, 1, mxREAL);
//            memcpy((void*)mxGetPr(SIN), (void*)SinArray, sizeof(double) * arraysize);
//            engPutVariable(m_pEngine, " SinGraph", SIN);
//            mxArray* COS = mxCreateDoubleMatrix(arraysize, 1, mxREAL);
//            memcpy((void*)mxGetPr(COS), (void*)CosArray, sizeof(double) * arraysize);
//            engPutVariable(m_pEngine, " CosGraph", COS);
//            mxArray* DEG = mxCreateDoubleMatrix(arraysize, 1, mxREAL);
//            memcpy((void*)mxGetPr(DEG), (void*)Degrees, sizeof(double) * arraysize);
//            engPutVariable(m_pEngine, " Degrees", DEG);
//            engEvalString(m_pEngine, "figure('units','normalized','outerposition',[0 0 1 1]),");
//            engEvalString(m_pEngine, " plot(Degrees,SinGraph,'r',Degrees,CosGraph,'b'), grid minor, title('Our Matlab Plot ' ),");
//            system("pause");
//        }
//        else if (Sim == '2') {
//            mxArray* dSIN = mxCreateDoubleMatrix(1, 1, mxREAL);
//            mxArray* dCOS = mxCreateDoubleMatrix(1, 1, mxREAL);
//
//            mxArray* dDEG = mxCreateDoubleMatrix(1, 1, mxREAL);
//            double* pSIN = mxGetPr(dSIN);
//            double* pCOS = mxGetPr(dCOS);
//            double* pDEG = mxGetPr(dDEG);
//               for (int i = 0; i < 1000; i++) {
//                     *pSIN = SinArray[i];
//                     *pCOS = CosArray[i];
//                     *pDEG = Degrees[i];
//                     engPutVariable(m_pEngine, "dSIN", dSIN);
//                     engPutVariable(m_pEngine, "dCOS", dCOS);
//                     engPutVariable(m_pEngine, "dDEG", dDEG);
//                     engEvalString(m_pEngine, "sactter(dDEG,dSIN,200,'r','filled'),set(gca,'YLim',[0 1000],'XLim',[0 100]),hold on, ");
//                     engEvalString(m_pEngine, "scatter(dDEG,dCOS,200,'b','filled'),hold off");
//
//                 }
//                 
//                 engEvalString(m_pEngine, "parcela(T,D);");
//            engEvalString(m_pEngine, "title('EFICIENCIA DE ALGORITMO');");
//            engEvalString(m_pEngine, "xlabel('TIEMPO DE EJECUCION');");
//            engEvalString(m_pEngine, "ylabel('DATOS');");
//            engEvalString(m_pEngine, "x=1:15);");
//            engEvalString(m_pEngine, "y=x.^2;");
//            engEvalString(m_pEngine, "plot(x,y);");
//
//
//            mxDestroyArray(T);
//        }
//
//    }