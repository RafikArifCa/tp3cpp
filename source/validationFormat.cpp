/**
 * \file validationFormat.cpp
 * \brief
 * \author Thierry Eude
 * \version 3
 * \date 2021-09-01
 */
#include <iostream>
#include <sstream> //pour pouvoir utiliser le istringstream
#include "validationFormat.h"
using namespace std;

namespace util
{


  /**
   * \brief valide le format de noms, que des lettres espaces possibles.
   * \param[in] p_nom le nom à valider
   * \return true si le nom est valide false sinon
   */
  bool
  validerFormatNom (const std::string &p_nom)
  {
    bool valide = true;
    int compteur = 0;
    for (unsigned i = 0; i < p_nom.size (); ++i)
      {
        if (p_nom[i] == ' ' || p_nom[i] == '-')
          {
            compteur++;
          }
        else
          {
            compteur = 0;
          }
        if ((!isalpha (p_nom[i]) && p_nom[i] != ' ' && p_nom[i] != '-') ||
            compteur > 1)
          {
            valide = false;
          }
      }
    return valide;
  }


  /**
   * \brief valide le format ISSN 9999-9999 ainsi que la validité de la clé.
   * \param[in] p_issn le code à valider
   * longueur 14
   * commence par ISSN
   * [5] est un espace
   * [9] est un -
   * le reste que des chiffres
   * clé valide
   * \return true si le nom est valide false sinon
   */
  bool
  validerCodeIssn (const std::string &p_issn)
  {
    bool valide = false;
    int somme = 0;
    int multiplicateur = 8;

    if (p_issn.compare (0, 5, "ISSN ") == 0)
      {
        if (p_issn.length () == 14 && p_issn[9] == '-')
          {
            bool chiffre = true;
            for (unsigned int i = 5; i < p_issn.length () - 1; i++)
              {
                if (i == 9)
                  {
                    i++;
                  }

                if (isdigit (p_issn[i]))
                  {
                    somme += (p_issn[i] - '0') * multiplicateur;
                    multiplicateur--;
                  }
                else
                  {
                    chiffre = false;
                  }
              }
            if ((11 - somme % 11 == p_issn[13] - '0') && chiffre)
              {
                valide = true;
              }
          }
      }
    return valide;
  }


  /**
   * \brief vérifie la validité du code ISBN-13
   * doit commencer pas ISBN
   * si longueur == 5 + 13 + 4
   * si longueur 13 (10 + 3 tirets) et début  est 978 ou 979
   * lire le premier groupe A; avec getline et délimiteur -
   * ajouter dans code, variable locale string
   * si A : Domaine
   * Le code de Domaine peut avoir de 1 à 5 chiffres selon la structure suivante :
          0-5, 7
          600-649
          80-94
          950-989
          9900-9989
          99900-99999
   * lire le deuxième groupe B; avec getline et délimiteur -
   * B : Numéro éditeur
   *  00 - 19
          200 - 699
          7000 - 8499
          85000 - 89999
          900000 - 949999
          9500000 - 9999999
   * concaténer dans code
   * lire le troisième groupe C; avec getline et délimiteur -
   * C : Numéro de publication (pas de contrainte)
   * concaténer dans code
   * lire le denier groupe D; avec >> dans une variable locale
   * concaténer dans code
   * code contient alors le code isbn sans les tirets
   * vérifier le clé
   * \param[in] p_isbn le code à valider
   * isbn-13 : ISBN 978-2-1234-5680-3
   * \return true si valide
   */
  bool
  validerCodeIsbn (const std::string &p_isbn)
  {
    bool valide = false;
    istringstream is_isbn (p_isbn);
    // le code doit commencer par ISBN
    string prefixe; // = p_isbn.substr(0, 5);
    char buffer[256];
    is_isbn.getline (buffer, 256, ' ');
    prefixe = buffer;
    if (prefixe == "ISBN")
      {
        string code_isbn;
        // ISBN-13
        if (p_isbn.size () == 5 + 13 + 4)
          {
            char buffer[256];
            // Bookland
            is_isbn.getline (buffer, 255, '-');
            code_isbn = buffer;
            if (code_isbn == "978" || code_isbn == "979")
              {
                //              cout << "pays valide" << endl;
                // groupe A
                is_isbn.getline (buffer, 255, '-');
                string domaine = buffer;
                int codeDomaine = atoi (domaine.c_str ());
                if ((codeDomaine >= 0 && codeDomaine <= 5) ||
                    codeDomaine == 7 ||
                    (codeDomaine >= 600 && codeDomaine <= 649) ||
                    (codeDomaine >= 80 && codeDomaine <= 94) ||
                    (codeDomaine >= 950 && codeDomaine <= 989) ||
                    (codeDomaine >= 9900 && codeDomaine <= 9989) ||
                    (codeDomaine >= 99900 && codeDomaine <= 99999))
                  //    0-5, 7
                  //    600-649
                  //    80-94
                  //    950-989
                  //    9900-9989
                  //    99900-99999
                  {
                    //                  cout << "domaine valide" << endl;
                    code_isbn += domaine;
                    // groupe B
                    is_isbn.getline (buffer, 255, '-');
                    string editeur = buffer;
                    int numeroEditeur = atoi (editeur.c_str ());

                    if ((numeroEditeur >= 0 && numeroEditeur <= 19) ||
                        (numeroEditeur >= 200 && numeroEditeur <= 699) ||
                        (numeroEditeur >= 7000 && numeroEditeur <= 8499) ||
                        (numeroEditeur >= 85000 && numeroEditeur <= 89999) ||
                        (numeroEditeur >= 900000 && numeroEditeur <= 949999) ||
                        (numeroEditeur >= 9500000 &&
                         numeroEditeur <= 9999999))
                      {
                        // 00 - 19
                        //    200 - 699
                        //    7000 - 8499
                        //    85000 - 89999
                        //    900000 - 949999
                        //    9500000 - 9999999
                        //                      cout << "editeur valide" <<
                        //                      endl;

                        code_isbn += editeur;
                        // groupe C
                        is_isbn.getline (buffer, 255, '-');
                        code_isbn += buffer;
                        // groupe D
                        string cle_str;
                        is_isbn >> cle_str;
                        code_isbn += cle_str;
                        // Validation du code ISBN-13 à partir de la clé de
                        // vérification
                        // cout << code_isbn << endl;
                        int sommeProduits = 0;
                        for (unsigned int position = 0; position < 12;
                             position++)
                          {
                            sommeProduits += ((position % 2 == 0) ? 1 : 3) *
                                    (code_isbn[position] - '0');
                          }

                        // ajout de la clé de contôle
                        sommeProduits += (code_isbn[12] - '0');

                        // La somme de produits doit être un multiple de 10
                        if (sommeProduits % 10 == 0)
                          {
                            valide = true;
                          }
                      }
                  }
              }
          }
      }
    // A : Code ISBN est valide : retourne vrai false sinon
    return valide;
  }


  bool
  validerAnnee (const string &annee)
  {
    for (auto ch : annee)
      {
        // doit etre des chiffres
        if (ch > '0' || ch < '9')
          {
            return false;
          }
      }
    return true;
  }


  //  bool
  //  isValidISBN (const string &isbn_number)
  //  {
  //    int count = 0;
  //
  //    if (isbn_number[0] != 'I' || isbn_number[1] != 'S' ||
  //        isbn_number[2] != 'B' || isbn_number[3] != 'N' ||
  //        isbn_number[4] != ' ')
  //      {
  //        return false;
  //      }
  //
  //    string reste = isbn_number.substr (5);
  //
  //    if (!(reste[0] == '9' && reste[1] == '7' &&
  //          (reste[2] == '9' || reste[2] == '8')))
  //      {
  //        return false;
  //      }
  //
  //    if (reste[3] != '-' || reste[5] != '-' || reste[9] != '-' ||
  //        reste[15] != '-')
  //      {
  //        return false;
  //      }
  //
  //    if (reste.length () != 17)
  //      {
  //        return false;
  //      }
  //
  //    for (int i = 0; i < reste.length (); i++)
  //      {
  //        char ch = reste[i];
  //
  //        /* echapper - et ' ' */
  //        if (ch == ' ' || ch == '-')
  //          {
  //            continue;
  //          }
  //        // doit etre des chiffres
  //        if (ch < '0' || ch > '9')
  //          {
  //            return false;
  //          }
  //      }
  //
  //    return true;
  //  }
  //
  //
  //  bool
  //  isValidISSN (const string &isbn_number)
  //  {
  //    if (isbn_number[0] != 'I' || isbn_number[1] != 'S' ||
  //        isbn_number[2] != 'S' || isbn_number[3] != 'N' ||
  //        isbn_number[4] != ' ')
  //      {
  //        return false;
  //      }
  //
  //    string reste = isbn_number.substr (5);
  //
  //    if (reste[4] != '-')
  //      {
  //        return false;
  //      }
  //
  //    if (reste.length () != 9)
  //      {
  //        return false;
  //      }
  //
  //    for (int i = 0; i < reste.length (); i++)
  //      {
  //        char ch = reste[i];
  //
  //        /* echapper - et ' ' */
  //        if (ch == ' ' || ch == '-')
  //          {
  //            continue;
  //          }
  //        // doit etre des chiffres
  //        if (ch < '0' || ch > '9')
  //          {
  //            return false;
  //          }
  //      }
  //
  //    return true;
  //  }

} // namespace util
