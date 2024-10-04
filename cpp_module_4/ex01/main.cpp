/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:48:50 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/07 10:51:50 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	std::cout << ">>>> Polymorphism Test <<<<" << std::endl;
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << std::endl;

	std::cout << ">>>> Brain Check <<<<" << std::endl;
	Cat *orignalCat = new Cat();
	orignalCat->getBrain().setIdea(1, "Go for a walk");
	std::cout << "Original Cat's first idea: " << orignalCat->getBrain().getIdea(1) << std::endl;
	Cat *copyCat =  new Cat(*orignalCat);
	std::cout << "Copied Cat's First idea:" << copyCat->getBrain().getIdea(1) << std::endl;
	copyCat->getBrain().setIdea(90, "Sleep in the sun");
	std::cout << "Copied Cat's other idea:" << copyCat->getBrain().getIdea(90) << std::endl;
	std::cout << "Copied Cat's first idea:" << copyCat->getBrain().getIdea(1) << std::endl;

	delete orignalCat;
	delete copyCat;

	std::cout << std::endl;

	std::cout << ">>>> Assignment Operator Check <<<<" << std::endl;
	Cat *cat1 = new Cat();
	cat1->getBrain().setIdea(1, "Watch birds");
	Cat *cat2 = new Cat();
	*cat2 = *cat1;
	cat2->getBrain().setIdea(1, "Knock over plants");
	std::cout << "Cat1's first idea after Cat2 changed: " << cat1->getBrain().getIdea(1) << std::endl;
	std::cout << "Cat2's first idea: " << cat2->getBrain().getIdea(1) << std::endl;

	delete cat1;
	delete cat2;

	return (0);
}