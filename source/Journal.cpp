/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Journal.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <string>
#include <sstream>
#include "Reference.h"

using namespace std;


namespace biblio
{


  Journal::Journal (const string& p_auteurs, const string& p_titre, int p_annee, const string& p_identifiant, const string& p_nom, int p_volume, int p_numero, int p_page) :
  Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_volume (p_volume), m_numero (p_numero), m_page (p_page), m_nom (p_nom)
  {

    PRECONDITION (!p_nom.empty ());



    PRECONDITION (isdigit (p_volume));
    PRECONDITION (isdigit (p_numero));
    PRECONDITION (isdigit (p_page));
    PRECONDITION (p_volume > 0);
    PRECONDITION (p_numero > 0);
    PRECONDITION (p_page > 0);



    PRECONDITION (util::validerCodeIssn (p_identifiant));
    POSTCONDITION ( m_nom == p_nom);
    POSTCONDITION (m_volume == p_volume);
    POSTCONDITION (m_numero == p_numero);
    POSTCONDITION (m_page == m_page);

    INVARIANTS ();
  }


  const string&
  Journal::reqNom () const
  {

    return m_nom;
  }


  int
  Journal::reqVolume () const
  {
    return m_volume;
  }


  int
  Journal::reqNumero () const
  {
    return m_numero;
  }


  int
  Journal::reqPage () const
  {
    return m_page;
  }


  Reference*
  Journal::clone () const
  {
    return new Journal (*this);
  }


  const string
  Journal::reqReferenceFormate () const
  {
    std::ostringstream os;

    os << Reference::reqReferenceFormate () << "." << m_nom << "."  << m_volume << "." << m_numero << "." << m_page << "." << Reference::reqAnnee () << "." << Reference::reqIdentifiant ();
    return os.str ();

  }


  void
  Journal::verifieInvariant () const { }
}//fin du namespace biblio

