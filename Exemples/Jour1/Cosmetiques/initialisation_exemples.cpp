static_assert(__cplusplus >= 202002L, "C++ 20 ou supérieur obligatoire !");
#include <iostream>
#include <string>
#include <vector>
#include <array>

struct Produit
{
  std::string nom{""};
  double      prix{0.};
  long        reference{0L};
};

std::array<Produit, 255> produits_limites;

bool addProduitAt( int t_index, Produit const& t_produit )
{
  if ( (t_index >= 255) || (t_index < 0) )
    return false;
  produits_limites[t_index] = t_produit;
  return true;
}

namespace Geometry
{
  std::array<std::array<double,3>,3> identity()
  {
    return { std::array{1.,0.,0.},
                       {0.,1.,0.},
	               {0.,0.,1.} };
  }
}

struct GmresOptions
{
  int numberRhs = 1;
  double const* preconditionner{nullptr};
  double relativeError = 1.E-6;
  std::uint32_t numberOfOuterIterations = 1;
  std::uint32_t numberOfInnerIterations =20;
  bool   isVerbose = false;
};

std::vector<double>
gmres(int dimension,double const* A,double const* b,
      GmresOptions const& options ) {
  std::cout << "GMRES( dimension : " << dimension
	    << ",A : " << (void const*)A << ", b : "
            << (void const*)b << ", numRhs : " << options.numberRhs
            << ", preconditionner : " << (void const*)options.preconditionner
            << ", relative error : " << options.relativeError
	    << ", number of outer iterations : " << options.numberOfOuterIterations
            << ", number of inner iterations : " << options.numberOfInnerIterations
            << ", is Verbose :" << std::boolalpha << options.isVerbose
            << " )" << std::endl;
  return {};
}

int main()
{
  if (!addProduitAt(10, {"Bouteille", 1.5, 13943L}))
    {
      std::cout << "Failed to add new article !" << std::endl;
    }
  if (!addProduitAt(0, {.nom="Chocolat", .prix=2.5, .reference=156478L}))
    {
      std::cout << "Failed to add new article !" << std::endl;
    }
  double const A[]={1.,0.,0.,0.,1.,0.,0.,0.,1.};
  double const b[]={1.,1.,1.};
  // En 98, on aurait été obligé au mieux d'avoir un appel comme :
  // gmres(3,A,b,1,nullptr, 1.E-6, 1, 20, true); !
  std::vector<double> res = gmres(3, A, b, {.relativeError=1.E-14, .isVerbose=true} );
  
  return EXIT_SUCCESS;
}

  
