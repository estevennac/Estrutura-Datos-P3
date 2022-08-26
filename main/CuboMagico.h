#ifndef CUBOMAGICO_H
#define CUBOMAGICO_H
	class CuboMagico{
		public:
			CuboMagico();
			CuboMagico(int **);	
			void setCuboMagicoCuadrado(int **);
			int **getCuboMagicoCuadrado();
			void mostrar(int, int);
			void llenar(int, int, int, int);
		protected:	
		private:
			int **cuadrado;
	};
#endif 
