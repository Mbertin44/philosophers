<p align="center">
  <img src="https://github.com/byaliego/42-project-badges/blob/main/badges/philosophers.png?raw=true">
</p>

# Projet Philosophers

Le projet Philosophers est un projet de l'école 42 qui consiste à résoudre le problème classique de la synchronisation des processus connu sous le nom de problème des philosophes dîneurs. Le but est de concevoir un programme qui simule le comportement des philosophes qui partagent une table ronde et qui ont besoin de prendre leurs fourchettes pour manger, mais qui ne peuvent prendre une fourchette que si elle est disponible et qui ne peuvent manger que s'ils ont les deux fourchettes.

## Fonctionnalités disponibles

Le programme simule le comportement des philosophes et permet de contrôler le nombre de philosophes, le temps de réflexion, le temps de prise de fourchettes et le temps de manger. Les fonctionnalités disponibles incluent :

- Gestion de plusieurs philosophes en même temps
- Utilisation de threads pour simuler les philosophes
- Utilisation de mutex pour synchroniser l'accès aux fourchettes
- Affichage de l'état des philosophes en temps réel
- Possibilité de configurer les paramètres du programme via des arguments en ligne de commande

## Utilisation

Pour utiliser le programme, vous pouvez le compiler en utilisant le Makefile fourni. Une fois compilé, vous pouvez exécuter le programme en fournissant les arguments souhaités. Les arguments disponibles sont :

- number_of_philosophers : Le nombre de philosophes, mais aussi le nombre de fourchettes. (minimun 1 et maximum 200)
- time_to_die (en millisecondes) : Si un philosophe n’a pas commencé à manger time_to_die millisecondes après le début de son précédent repas ou depuis le début de la  simulation, il meurt.
- time_to_eat (en millisecondes) : Le temps qu’un philosophe prend à manger. Pendant ce temps, un philosophe doit garder ses deux fourchettes.
- time_to_sleep (en millisecondes) : Le temps qu’un philosophe passe à dormir.
- number_of_times_each_philosopher_must_eat (argument optionnel) : Si tous les philosophes ont mangé au moins number_of_times_each_philosopher_must_eat fois, la simulation prend fin. Si cet argument n’est pas spécifié, alors la simulation prend fin à la mort d’un philosophe.

Voici un exemple d'utilisation :

`./philo 5 800 200 200`

Ce qui lance le programme avec 5 philosophes, un temps de 800 ms avant de mourir, mange pendant 200 ms et un dort pendant 200 ms.

## Compilation

Pour compiler le programme, vous pouvez utiliser le Makefile fourni. La commande "make" compilera le programme et créera un exécutable nommé "philo".
