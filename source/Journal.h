
/*
 * File:   Journal.h
 * Author: etudiant
 *
 * Created on 20 novembre 2022, 13:27
 */
#ifndef JOURNAL_H
#define JOURNAL_H

#include "Reference.h"
#include <string>
#include "ContratException.h"

namespace biblio
{

  class Journal : public Reference
  {
  public:
    Journal (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_nom, int p_volume, int p_numero, int p_page);

    const std::string& reqNom ()const;
    int reqVolume () const;
    int reqNumero ()const;
    int reqPage ()const;
    virtual const std::string reqReferenceFormate ()const;
    virtual Reference* clone ()const;

  private:
    void verifieInvariant () const;
    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;
  };
}//fin du namespace biblio
#endif /* JOURNAL_H */

