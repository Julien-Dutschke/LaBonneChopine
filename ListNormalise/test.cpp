#include "ListNormalise.hpp"

int main()
{
    try
	{
		//? Exemple d'utilisation avec une vecteur d'entiers
		//? Valeur autoriser [int ,double , float, ...]
        std::vector<int> input = {10, 20,5000 , 42000};

        VectorNormalizer<int> normalizedVector(input);

        std::cout << "Valeur minimale: " << normalizedVector.getMinValue() << std::endl;
        std::cout << "Valeur maximale: " << normalizedVector.getMaxValue() << std::endl;

		normalizedVector.addValue(420);

        std::cout << "Vecteur normalisé: \n";
	
		normalizedVector.printNormalizedVector();
	}

    catch (const std::invalid_argument& e)
    {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}
