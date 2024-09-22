- probleme de leaks avec split








































Avec Elise K. :
- input : SPLIT, 
- sort > 100 nombres (100 ok)
- doublons et... 0 et -0

- 't_stack **stack' -> modifiable
- 't_stack *stack' -> non-modifiable

Moni :
// OK - trier 2 nombres 
// OK - trier 1 nombre, implicite
// OK - trier 0 nombre, implicite

./ps "   3 4 65 2 1"
3 4 5 2 7


// OK - isdigitorspace -> checkers

// OK - is_int -> new_node.c
_____________________________________________________
*****************************************************

OU JEN SUIS :

- split ok
- clean space ok

- par contre, implementation ne fonctionne pas. 
	- sans guillemets oui
	- avec guillemets NON !!! :(

_____________________________________________________

corr split
implementation dans ps

essayer de reecrire split par moi-meme


















sort_3, sort_4, sort_5, sort_n OK

pour les serie jusqua 100 cest ok mais pas super optimal.
pour les serie jusqua 500 ca CRASH :( OH NO !!

// chose sort OK

format output 
	\n
	retirer printstack

format input
	split

CHECKERS

	is_not_digit		KO		|
	is_doublon			KO		|_ 	EROR
	is_long				KO		|			
	wrong_sort			KO		|	
	
	any_param			-
	only_once_param		-

	is_already_sorted	-		OK
	is_sorted_now		-		OK

{
Paramètres non numériques		Retourner Error si des valeurs non numériques sont fournies.
Nombres en double				Retourner Error s'il y a des doublons dans les nombres d'entrée.
Nombre dépassant INT_MAX		Retourner Error si un nombre dépasse la limite des entiers (INT_MAX).
Aucun argument fourni			Le programme ne doit rien afficher et retourner simplement à l'invite de commande.
Instructions invalides			Retourner Error si des instructions non valides sont entrées lors de l'exécution.
Tests pour un tri incorrect		Tester que les instructions incorrectes renvoient bien KO.
Mauvaises instructions			Par exemple, des commandes comme sa, pb, rrr sur une liste mélangée doivent retourner KO.
Vérifications de tri correct	Tester que les bonnes instructions renvoient bien OK.
Liste triée après commandes		Après avoir exécuté les bonnes instructions pour une liste, le programme doit afficher OK.
Liste déjà triée				Le programme doit retourner OK immédiatement si la liste est déjà triée à l'origine.
}













// pas de doublons - eror
// limites du int - eror
// digit - eror
// split " "
// Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre
//		l’invite de commande.
// SEGV a traiter OK


// sort_3 OK

// OK sort_all : probleme avec des zero au debut 
	// ils sont plus bas, par contre il doit y avoir un soucis de pointeur pour le debut de la liste


// Il y a toujours un leaks avec stack_b
// 	free_stack(stack_b) ->  definitely lost: 32 bytes in 1 blocks
// suppression de malloc pour stack_b. ca lair de fonctionner 

