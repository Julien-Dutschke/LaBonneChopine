#ifndef __LISTNORMALISE_HPP__
# define __LISTNORMALISE_HPP__
# include <iostream>
# include <vector>
# include <iomanip>
# include <algorithm>

template <typename T>
class VectorNormalizer
{
    private:
        T minValue;
        T maxValue;
        std::vector<double> normalizedVector;
    
    public:
        // ! Constructeur qui prend un vecteur de type T
        //? Valeur autoriser std::vector<[int || double || float || ...]>
        VectorNormalizer(const std::vector<T>& inputVector)
        {
            if (inputVector.empty())
            {
                throw std::invalid_argument("Le vecteur ne peut pas être vide.");
            }
    
            //* Trouver les valeurs minimales et maximales
            minValue = *std::min_element(inputVector.begin(), inputVector.end());
            maxValue = *std::max_element(inputVector.begin(), inputVector.end());
    
            //* Normaliser le vecteur
            for (const T& value : inputVector)
            {
                if (maxValue != minValue)
                {
                    normalizedVector.push_back((static_cast<double>(value) - minValue) / (maxValue - minValue));
                }
                else 
                {
                    normalizedVector.push_back(0.0); // Cas où tous les éléments sont égaux
                }
            }
        }
        

        //* Ajoute une valeur et la normaliser si elle est dans l'intervalle [minValue, maxValue]
        bool addValue(const T& newValue)
        {
            if (newValue >= minValue && newValue <= maxValue)
            {
                double normalizedValue = (static_cast<double>(newValue) - minValue) / (maxValue - minValue);
                normalizedVector.push_back(normalizedValue);
                return true;
            }
            else
                return false;
        }
    
        // Fonction pour obtenir la valeur minimale
        T getMinValue() const
        {
            return minValue;
        }

		// Fonction pour obtenir la valeur maximale
        T getMaxValue() const 
        {
            return maxValue;
        }
    
        // Fonction pour obtenir le vecteur normalisé
        std::vector<double> getNormalizedVector() const
        {
            return normalizedVector;
        }


		void printNormalizedVector(int precision = 2, bool scientificNotation = false)
		{
			if (scientificNotation == true)
				std::cout << std::scientific;
			else
				std::cout << std::fixed;
			for (const double& value : normalizedVector)
			{
				std::cout << std::setprecision(precision) << value << std::endl;
			}
			std::cout << std::endl;
		}
};

# endif // __LISTNORMALISE_HPP__