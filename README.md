# Push_Swap
Sorting in an ascending order a Stack A, only using  4 types of commands and another Stack B

<details>
    <summary>Cheminement</summary>
- ***LEXICO***
    - Complexité :la *quantité de ressources* (temps, espace mémoire, etc.) dont a besoin un [algorithme](https://fr.wikipedia.org/wiki/Algorithme) pour résoudre un *[problème algorithmique](https://fr.wikipedia.org/wiki/Probl%C3%A8me_algorithmique)*
        

# **GOAL** :

Sort given range of unique integers using two stacks (A and B) and only following operations:

- Possible operations
    
    **sa** : swap a - swap the first 2 elements at the top of stack a.
    
    Do nothing if there is only one or no elements).
    
    **sb**: swap b - swap the first 2 elements at the top of stack b.
    
    Do nothing if there is only one or no elements).
    
    **ss**: sa and sb at the same time.
    
    **pa**: push a - take the first element at the top of b and put it
    
    at the top of a. Do nothing if b is empty.
    
    **pb**: push b - take the first element at the top of a and put it
    
    at the top of b. Do nothing if a is empty.
    
    **ra**: rotate a - shift up all elements of stack a by 1. The first
    
    element becomes the last one.
    
    **rb**: rotate b - shift up all elements of stack b by 1. The first
    
    element becomes the last one.
    
    **rr** : ra and rb at the same time.
    
    **rra** : reverse rotate a - shift down all elements of stack a by 1.
    
    The last element becomes the first one.
    
    **rrb** : reverse rotate b - shift down all elements of stack b by 1.
    
    The last element becomes the first one.
    
    **rrr**: rra and rrb at the same time.
    
    
- gestion d'erreurs
    
    args > 2, int seulement, prend les nombres negatifs sinon affiche **Error en sortie d'erreur** (fd = 2) 
    

 EXECUTABLE : **./push_swap int int int ...**

- Restrictions
    1. 2-3 operations for 3 integers
    2.  12 operations for 5 integers
    3. 700 operations for 100 integers
    4. 5500 operations for 500 integers
    
    Max points
    
    HUNK pour 100 → 700
    
    HUNK pour 500 → 5500
    
- Important note : tris, algo
    
    **The algortihm**
    
    While the aim of the project was to introduce students to complexity**, the project did not actually favour algorithms with lowest complexity**. Given that highest marks were achieved by using the least amount of commands, slower algorithms that read the data more times could be more precise than algortihms optimised for speed or least passes over the numbers. For this reason, computationally slower processes like finding the true median for each split in quick sort achieved better results.
    

## CHEMINEMENT:

**ETAPE 1**

Avant de programmer la méthode de résolution go initialiser des t_list qui vont représenter les stacks . De plus une fonction t_list ft_fillstack (int ac, char **av) qui va stocker les arguments dans t_list qui sera notre stack_a. Et des fonctions de gestion d'erreurs : ft_checkduplint(t_list stack *) et ft_check_max_int( t_list stack*).

- LES VARIABLES
    
    t_list : ***stack_a *stack_b**
    
    s_list operation, composée de char *opr qui va stocker les opérations effectuées afin de pouvoir les imprimer en fin de programme.
    
- fonctions utilitaires ajoutées à ma libft
    - **ft_atoll ft_atol :** str to long long
    - void ft_lst_int_print (t_list list): print une liste chainée
    - int ft_lst_int_check_order(t_list list): renvoie 1 si la liste est ordonnée en ordre croissant
    - t_list *ft_lst_int_search(t_list list, int nb): renvoie un pointeur vers l'element trouvé ou NULL
    - int ft_lst_int_occurence(t_list list, long nb): compte le nombre d'occurencesde nb
    - ft_tab_long_print
    - ft_tab_long_sort
    
    Self-explanatory
    

# SORTING

## SORTING avec 3 valeurs

- Initialise 3 variables pour 3 int. On a 5 cas differents
    - **if n1 = min et n2 = max             case = 1 3 2**
        
        SA
        
        RA
        
    - **else if n1 = max et n2 = min      case = 3 1 2**
        
        RA
        
    - **else if n1 = max  et  n3 = min    case = 3 2 1**
        
        RA 
        
        SA
        
    - if n2 = min et n3 = max              case = 2 1 3
        
        SA
        
    - if n2 = max et n3 = min              case = 2 3 1
        
        RRA
        

## **SORTING IN GENERAL :**

### TYPES OF SORTING

- TYPES OF SORTING
    - TRI PAR INSERTION (= INSERTSORTING )
        
        ![Insertion-sort-example-300px.gif](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3c0a7c89-5a12-4e5b-bb1d-29bcd8427ffe/Insertion-sort-example-300px.gif)
        
    - TRI FUSION
        
        je divise en deux puis je tri chacune des parties
        
    - RADIX SORTING
        
        chiffre par chiffre en commençant par les unités
        
        *ex:* 23 ; 7 ; 122; 19
        
         
        
        1.  122  23 7  19
        2. 7 19 122 23
        3. 7 19 23 122 
        
    - QUICK SORTING
        
        [https://www.youtube.com/watch?v=JyXNda9Frrw](https://www.youtube.com/watch?v=JyXNda9Frrw) (explications claires sur excel) version python
        
        [https://www.youtube.com/watch?v=COk73cpQbFQ](https://www.youtube.com/watch?v=COk73cpQbFQ) same version Cv  
        
        - utilisation d'un pivot = dernier element de la liste (index max)
        - trouver element  sup > au pivot en comment par index 0
        - si element inferieur sup les inverser
        - en boucle jusque ce que pivot soit entouré de valeurs inférieures à gauche et supérieures à droite
        
        *ex:* sa 
        
    - BULLY
    - COMPLEXITE AND SUMMARY
        
        ## **Complexité des algorithmes**
        
        Afin d’évaluer la complexité des différents algorithmes de tri présentés, on comptera le nombre de comparaisons et d’échanges de valeur entre deux éléments du tableau sans prendre en compte les affectations et comparaisons sur des variables de comptage de boucles.
        
        Les méthodes présentées sont de deux types :
        
        - des méthodes qui trient les éléments deux à deux, de manière plus ou moins efficace, mais qui nécessitent toujours de comparer chacun des N éléments avec chacun des N-1 autres éléments, donc le nombre de comparaisons sera de l’ordre de N — on note cet ordre de grandeur O(N^2). Par exemple, pour N=1000, N=10, pour N=10, N=10. Les algorithmes de ce type sont
            - une méthode de tri élémentaire, le tri par sélection ;
            - et sa variante, le tri par propagation ou tri bulle ;
            - une méthode qui s’apparente à celle utilisée pour trier ses cartes dans un jeu,le tri par insertion ;
        - des méthodes qui sont plus rapides, car elles trient des sous-ensembles de ces N éléments puis regroupent les éléments triés, elles illustrent le principe « diviser pour régner ». Le nombre de comparaisons est alors de l’ordre de N (log(N)). Par exemple, pour N=1000, N(log(N))=10000 environ, pour N=10, N(log(N))=20×10 environ. Les algorithmes de ce type sont :
            - **le fameux tri rapide ou *Quicksort* ;**
            - et enfin, **le tri par fusion.**
        
        Cette liste n’est évidemment pas exhaustive. Il existe des méthodes particulièr
        
    - void ft_strong_sorting(t_list **stack_a )
        
        variables : int **a,b**  t_list *stack_**b**
        

***“[Diviser pour reigner"]*** → quicksort, fusion sort

En informatique les mots *tri* et *trier* sont à prendre avec le sens de *classement* et *classer*.

### MY METHODS

- First try : HUNKS 750
- Second try : 900 ordering when pushing  median
- **Third try : Push all except 3 then push back the one that needs the fewer moves**
    </details>
***

## 42 Project 125/100
