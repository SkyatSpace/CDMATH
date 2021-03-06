/*
 * LinearSolver.hxx
 *
 *  Created on: 13 April. 2013
 *      Authors: CDMAT
 */

#ifndef LINEARSOLVER_HXX_
#define LINEARSOLVER_HXX_

#include <string>

#include <petsc.h>

#include "GenericMatrix.hxx"
#include "Vector.hxx"


class LinearSolver
{
    public: //----------------------------------------------------------------

	LinearSolver ( void ) ;

	~LinearSolver ( void ) ;

	LinearSolver( const GenericMatrix& matrix,
			const Vector& secondMember,
			int numberMaxOfIter,
			double tol,
			std::string nameOfMethod,
			std::string nameOfPc="" );

	const LinearSolver& operator= ( const LinearSolver& linearSolver ) ;

	LinearSolver ( const LinearSolver& LS ) ;

        void setMethod(std::string nameOfMethod) ;

        void setPreconditioner(std::string pc) ;

	int getNumberOfIter( void ) const ;

	bool getStatus( void ) const ;

	double getResidu( void ) const ;

	double getTolerance( void ) const ;

	int getNumberMaxOfIter( void ) const ;

	void setTolerance(double tol) ;

	void setNumberMaxOfIter(int numberMaxOfIter) ;

	Vector getSndMember( void ) const ;

	std::string getNameOfMethod( void ) const ;

	std::string getNameOfPc( void ) const ;

	Vector solve( void ) ;

	Vec vectorToVec( const Vector& myVector ) const ;

	Vector vecToVector(const Vec& vec) const ;

	void setMatrix(const GenericMatrix& matrix) ;

	void setSndMember(const Vector& secondMember) ;

	void setSingularity(bool sing) ;

	bool isSingular( void ) const;

        bool isSparseMatrix( void ) const ;

	Mat getPetscMatrix() const ;
	Vec getPetscVector() const ;

	void kspDuplicate(const KSP source, const Mat mat, KSP* destination) const;

	void precDuplicate(const PC source, const KSP ksp, PC* destination) const;


    private: //----------------------------------------------------------------

	void setLinearSolver(const GenericMatrix& matrix, const Vector& secondMember) ;
	KSP getPetscKsp() const ;
	PC getPetscPc() const ;

	double _tol;
	int _numberMaxOfIter;
	double _residu;
	bool _convergence;
	int _numberOfIter;
	bool _isSingular;
	bool _isSparseMatrix;
	std::string _nameOfPc;
	std::string _nameOfMethod;
	Vector _secondMember;
	Mat _mat;
	Vec _smb;
	PC _prec;
	KSP _ksp;

};

#endif /* LINEARSOLVER_HXX_ */
