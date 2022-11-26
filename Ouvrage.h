/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Ouvrage.h
 * Author: etudiant
 *
 * Created on 20 novembre 2022, 13:27
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H
#include "ContratException.h"
#include "Reference.h"


namespace biblio
{

  class Ouvrage : public Reference
  {
  public:
    Ouvrage (const std::string&p_auteurs, const std::string&p_titre,
             const int&p_annee, const std::string&p_identifiant,
             const std::string&p_editeur, const std::string&p_ville);

    const std::string& reqVille ()const;
    const std::string& reqEditeur ()const;


    virtual const std::string reqReferenceFormate ()const;
    virtual Reference* clone ()const;



  private:
    void verifieInvariant () const;
    std::string m_ville;
    std::string m_editeur;


  };
} //fin du namespace biblio

#endif /* OUVRAGE_H */


