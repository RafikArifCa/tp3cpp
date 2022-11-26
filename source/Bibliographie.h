
/*
 * File:   Bibliographie.h
 * Author: etudiant
 *
 * Created on 20 novembre 2022, 13:27
 */
#include "ContratException.h"
#include <vector>
#include "Reference.h"
#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

namespace biblio
{

  class Bibliographie
  {
  public:
    Bibliographie (const std::string& p_nomBibliographie);
    Bibliographie (const Bibliographie& p_bibliographie); //constructeur de copie
    ~Bibliographie ();


    const std::string reqNomBibliographie ()const;
    void ajouterReference (const Reference& p_nouvelleReference);
    const std::string reqBibliographieFormate () const;
    Bibliographie& operator= (const Bibliographie& p_bibliographie);


  private:

    bool referenceEstDejaPresente (const std::string&p_identifiant) const;
    void copierVector (const Bibliographie&p_bibliographie);
    void viderVector ();
    void verifieInvariant ()const;


    std::string m_nomBibliographie;
    std::vector<Reference*> m_vReferences;


  };

} //fin du namespace biblio

#endif /* BIBLIOGRAPHIE_H */

