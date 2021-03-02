312CB_Picior_Catalin

	Pentru a usura lucrul cu adrese in format X.X.X.X, am construit functia
prel_adresa, care citeste cei 4 octeti, ii shifteaza la stanga pe fiecare
in parte si ii "alatura"(prin "sau" logic) intr-un unsigned int, facilitand
aflarea adreselor de retea sau de broadcast pentru anumite task-uri.
	Cele 4 functii, dec_to_adresa, dec_to_adresa_oct, dec_to_adresa_hex si
adress_to_bin transforma o adresa stocata intr-un unsigned int, in format 
X.X.X.X si o afiseaza in baza 10, 8, 16, respectiv 2.
	Functia mask_to_dec transforma o masca de retea, despre care stim doar
numarul de biti setati pe 1, intr-un unsigned int, in care stocheaza toti
bitii. Se porneste de la numarul cu toti cei 32 de biti setati pe 1 si se
shifteaza la stanga cu numarul de zerouri din masca ceruta.
	Functia is_same_network verifica daca 2 adrese fac parte din aceeasi retea,
comparand adresele lor de retea, stocate in format unsigned int.
	Functia is_msk_correct verifica daca o masca de retea stocata intr-un
unsigned int este corecta. Consideram ca masca este corecta, ceea ce inseamna
ca daca am adauga 1 la complementul acesteia, am obtine un numar cu un singur
bit setat pe 1(adica o putere a lui 2). Daca numarul precedent nu este putere
a lui 2, atunci masca este gresita(returnam 0), altfel este corecta(returnam 1)
	Functia correcting_mask transforma o masca gresita, in una corecta. Se 
parcurg toti bitii adresei, de la MSB la LSB contorizand pozitia primului bit
setat pe 0 intalnit. Shiftam succesiv la dreapta, apoi la stanga pentru a 
corecta bitii setati pe 1 in 0.
	In functia main a programului citim toate datele de intrare, folosind scanf
si functia prel_adresa. Pentru task-urile de la 0, pana la 4 inclusiv folosim 
functiile de afisare si calculam adresele de retea si de broadcast cerute.
	Pentru task-ul 5 comparam adresele de retea cu functia is_same_network.
	Pentru task-urile 6 si 7 se verifica daca msk_1 este corecta, iar in cazul
in care este gresita, se corecteaza si se afiseaza varianta corecta.
	Pentru task-ul 8 se afiseaza binar adresa ip_1, folosind functia dec_to_bin.
	Pentru task-ul 9, se calculeaza adresele curente de retea a lui ip_2 si a
adresei net, se compara intre ele si, in caz de egalitate, de afiseaza indicele
adresei net curente.



	
	



