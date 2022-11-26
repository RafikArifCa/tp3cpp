/**
 * \file Refrence.cpp
 * \brief Implementation de la classe Refrence
 * \author Etudiant
 * \date 22 octobre 2022
 */

#include "Reference.h"
#include <iostream>
#include <sstream>
#include "validationFormat.h"
#include "ContratException.h"

/**
 * \class Créé une classe référence
 * \brief
 */
namespace biblio
{


  /**
   * \brief Constructeur qui représente une référence
   * \param[in] p_auteur représente le nomd e l'auteur
   * \param[in] p_titre représente le titre de l'ourvage
   * \param[in] p_annee représente l'année d'édition
   * \param[in] p_identifiant représente l'identifiant de l'ouvrage
   * \return Un objet Reference
   */

  Reference::Reference (
                        const std::string &p_auteurs,
                        const std::string &p_titre,
                        int p_annee,
                        const std::string &p_identifiant)
  : m_auteurs (p_auteurs),
  m_titre (p_titre),
  m_annee (p_annee),
  m_identifiant (p_identifiant)
  {
    PRECONDITION (!p_auteurs.empty ());
    PRECONDITION (!p_titre.empty ());
    PRECONDITION (p_annee > 0);

    POSTCONDITION (m_auteurs == p_auteurs);
    POSTCONDITION (m_titre == p_titre);
    POSTCONDITION (m_annee == p_annee);

  }


  /**
   * \brief Créé une instance de l'objet référence
   * \return Chaîne de caractère contenant le titre de l'oeuvre, son auteur, sa
   * date de publication et son identifiant.
   */

  bool Reference::operator== (const Reference &p_reference) const
  {
    return m_identifiant == p_reference.m_identifiant &&
            m_titre == p_reference.m_titre && m_auteurs == p_reference.m_auteurs &&
            m_annee == p_reference.m_annee;
  }


  /**
   * \brief Accesseur auteur
   * \return un objet auteur
   */
  const std::string &
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /**
   * \brief Accesseur identifiant
   * \return Un objet identifiant
   */
  const std::string &
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \brief Accesseur titre
   * \return Un objet titre
   */
  const std::string &
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /**
   * \brief Accesseur année
   * \return Un objet année
   */
  int
  Reference::reqAnnee () const

  {
    return m_annee;
  }


  /**
   * \brief Mutateur année
   * \return Un objet année modifié
   */
  void
  Reference::asgAnnee (int annee)
  {
    m_annee = annee;
  }


  std::string const
  Reference::reqReferenceFormate () const
  {
    std::ostringstream os;
    os << m_auteurs << ", ";
    os << m_titre << ", ";
    os << m_annee << ", ";
    os << m_identifiant << ".";

    return os.str ();
  }

} // namespace biblio