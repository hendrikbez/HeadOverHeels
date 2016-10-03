// Copyright (C) 2005-2007 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file
//

// Begin prologue
//
//
// End prologue

#include <xsd/cxx/pre.hxx>

#include "ItemsXML.hpp"

namespace ixml
{
  // ItemsXML
  //

  const ItemsXML::item_sequence& ItemsXML::
  item () const
  {
    return this->item_;
  }

  ItemsXML::item_sequence& ItemsXML::
  item ()
  {
    return this->item_;
  }

  void ItemsXML::
  item (const item_sequence& item)
  {
    this->item_ = item;
  }


  // item
  //

  const item::door_optional& item::
  door () const
  {
    return this->door_;
  }

  item::door_optional& item::
  door ()
  {
    return this->door_;
  }

  void item::
  door (const door_type& door)
  {
    this->door_.set (door);
  }

  void item::
  door (const door_optional& door)
  {
    this->door_ = door;
  }

  void item::
  door (::std::auto_ptr< door_type > door)
  {
    this->door_.set (door);
  }

  const item::widthX_sequence& item::
  widthX () const
  {
    return this->widthX_;
  }

  item::widthX_sequence& item::
  widthX ()
  {
    return this->widthX_;
  }

  void item::
  widthX (const widthX_sequence& widthX)
  {
    this->widthX_ = widthX;
  }

  const item::widthY_sequence& item::
  widthY () const
  {
    return this->widthY_;
  }

  item::widthY_sequence& item::
  widthY ()
  {
    return this->widthY_;
  }

  void item::
  widthY (const widthY_sequence& widthY)
  {
    this->widthY_ = widthY;
  }

  const item::height_sequence& item::
  height () const
  {
    return this->height_;
  }

  item::height_sequence& item::
  height ()
  {
    return this->height_;
  }

  void item::
  height (const height_sequence& height)
  {
    this->height_ = height;
  }

  const item::directionFrames_type& item::
  directionFrames () const
  {
    return this->directionFrames_.get ();
  }

  item::directionFrames_type& item::
  directionFrames ()
  {
    return this->directionFrames_.get ();
  }

  void item::
  directionFrames (const directionFrames_type& directionFrames)
  {
    this->directionFrames_.set (directionFrames);
  }

  const item::mortal_type& item::
  mortal () const
  {
    return this->mortal_.get ();
  }

  item::mortal_type& item::
  mortal ()
  {
    return this->mortal_.get ();
  }

  void item::
  mortal (const mortal_type& mortal)
  {
    this->mortal_.set (mortal);
  }

  const item::weight_type& item::
  weight () const
  {
    return this->weight_.get ();
  }

  item::weight_type& item::
  weight ()
  {
    return this->weight_.get ();
  }

  void item::
  weight (const weight_type& weight)
  {
    this->weight_.set (weight);
  }

  const item::framesDelay_type& item::
  framesDelay () const
  {
    return this->framesDelay_.get ();
  }

  item::framesDelay_type& item::
  framesDelay ()
  {
    return this->framesDelay_.get ();
  }

  void item::
  framesDelay (const framesDelay_type& framesDelay)
  {
    this->framesDelay_.set (framesDelay);
  }

  const item::speed_type& item::
  speed () const
  {
    return this->speed_.get ();
  }

  item::speed_type& item::
  speed ()
  {
    return this->speed_.get ();
  }

  void item::
  speed (const speed_type& speed)
  {
    this->speed_.set (speed);
  }

  const item::bitmap_type& item::
  bitmap () const
  {
    return this->bitmap_.get ();
  }

  item::bitmap_type& item::
  bitmap ()
  {
    return this->bitmap_.get ();
  }

  void item::
  bitmap (const bitmap_type& bitmap)
  {
    this->bitmap_.set (bitmap);
  }

  void item::
  bitmap (::std::auto_ptr< bitmap_type > bitmap)
  {
    this->bitmap_.set (bitmap);
  }

  const item::shadow_optional& item::
  shadow () const
  {
    return this->shadow_;
  }

  item::shadow_optional& item::
  shadow ()
  {
    return this->shadow_;
  }

  void item::
  shadow (const shadow_type& shadow)
  {
    this->shadow_.set (shadow);
  }

  void item::
  shadow (const shadow_optional& shadow)
  {
    this->shadow_ = shadow;
  }

  void item::
  shadow (::std::auto_ptr< shadow_type > shadow)
  {
    this->shadow_.set (shadow);
  }

  const item::extraFrames_optional& item::
  extraFrames () const
  {
    return this->extraFrames_;
  }

  item::extraFrames_optional& item::
  extraFrames ()
  {
    return this->extraFrames_;
  }

  void item::
  extraFrames (const extraFrames_type& extraFrames)
  {
    this->extraFrames_.set (extraFrames);
  }

  void item::
  extraFrames (const extraFrames_optional& extraFrames)
  {
    this->extraFrames_ = extraFrames;
  }

  const item::frame_sequence& item::
  frame () const
  {
    return this->frame_;
  }

  item::frame_sequence& item::
  frame ()
  {
    return this->frame_;
  }

  void item::
  frame (const frame_sequence& frame)
  {
    this->frame_ = frame;
  }

  const item::label_type& item::
  label () const
  {
    return this->label_.get ();
  }

  item::label_type& item::
  label ()
  {
    return this->label_.get ();
  }

  void item::
  label (const label_type& label)
  {
    this->label_.set (label);
  }


  // door
  //

  door::
  door (value v)
  : ::xml_schema::string (_xsd_door_literals_[v])
  {
  }

  door::
  door (const ::xml_schema::string& v)
  : ::xml_schema::string (v)
  {
  }

  door::
  door (const door& v,
        ::xml_schema::flags f,
        ::xml_schema::type* c)
  : ::xml_schema::string (v, f, c)
  {
  }

  door& door::
  operator= (value v)
  {
    static_cast< ::xml_schema::string& > (*this) =
    ::xml_schema::string (_xsd_door_literals_[v]);

    return *this;
  }


  // bitmap
  //

  const bitmap::frameWidth_type& bitmap::
  frameWidth () const
  {
    return this->frameWidth_.get ();
  }

  bitmap::frameWidth_type& bitmap::
  frameWidth ()
  {
    return this->frameWidth_.get ();
  }

  void bitmap::
  frameWidth (const frameWidth_type& frameWidth)
  {
    this->frameWidth_.set (frameWidth);
  }

  const bitmap::frameHeight_type& bitmap::
  frameHeight () const
  {
    return this->frameHeight_.get ();
  }

  bitmap::frameHeight_type& bitmap::
  frameHeight ()
  {
    return this->frameHeight_.get ();
  }

  void bitmap::
  frameHeight (const frameHeight_type& frameHeight)
  {
    this->frameHeight_.set (frameHeight);
  }

  const bitmap::file_type& bitmap::
  file () const
  {
    return this->file_.get ();
  }

  bitmap::file_type& bitmap::
  file ()
  {
    return this->file_.get ();
  }

  void bitmap::
  file (const file_type& file)
  {
    this->file_.set (file);
  }

  void bitmap::
  file (::std::auto_ptr< file_type > file)
  {
    this->file_.set (file);
  }


  // shadow
  //

  const shadow::shadowWidth_type& shadow::
  shadowWidth () const
  {
    return this->shadowWidth_.get ();
  }

  shadow::shadowWidth_type& shadow::
  shadowWidth ()
  {
    return this->shadowWidth_.get ();
  }

  void shadow::
  shadowWidth (const shadowWidth_type& shadowWidth)
  {
    this->shadowWidth_.set (shadowWidth);
  }

  const shadow::shadowHeight_type& shadow::
  shadowHeight () const
  {
    return this->shadowHeight_.get ();
  }

  shadow::shadowHeight_type& shadow::
  shadowHeight ()
  {
    return this->shadowHeight_.get ();
  }

  void shadow::
  shadowHeight (const shadowHeight_type& shadowHeight)
  {
    this->shadowHeight_.set (shadowHeight);
  }

  const shadow::file_type& shadow::
  file () const
  {
    return this->file_.get ();
  }

  shadow::file_type& shadow::
  file ()
  {
    return this->file_.get ();
  }

  void shadow::
  file (const file_type& file)
  {
    this->file_.set (file);
  }

  void shadow::
  file (::std::auto_ptr< file_type > file)
  {
    this->file_.set (file);
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace ixml
{
  // ItemsXML
  //

  ItemsXML::
  ItemsXML ()
  : ::xml_schema::type (),
    item_ (::xml_schema::flags (), this)
  {
  }

  ItemsXML::
  ItemsXML (const ItemsXML& x,
            ::xml_schema::flags f,
            ::xml_schema::type* c)
  : ::xml_schema::type (x, f, c),
    item_ (x.item_, f, this)
  {
  }

  ItemsXML::
  ItemsXML (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f,
            ::xml_schema::type* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    item_ (f, this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e);
      this->parse (p, f);
    }
  }

  void ItemsXML::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // item
      //
      if (n.name () == "item" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< item_type > r (
          item_traits::create (i, f, this));

        this->item ().push_back (r);
        continue;
      }

      break;
    }
  }

  ItemsXML* ItemsXML::
  _clone (::xml_schema::flags f,
          ::xml_schema::type* c) const
  {
    return new ItemsXML (*this, f, c);
  }

  // item
  //

  item::
  item (const directionFrames_type& directionFrames,
        const mortal_type& mortal,
        const weight_type& weight,
        const framesDelay_type& framesDelay,
        const speed_type& speed,
        const bitmap_type& bitmap,
        const label_type& label)
  : ::xml_schema::type (),
    door_ (::xml_schema::flags (), this),
    widthX_ (::xml_schema::flags (), this),
    widthY_ (::xml_schema::flags (), this),
    height_ (::xml_schema::flags (), this),
    directionFrames_ (directionFrames, ::xml_schema::flags (), this),
    mortal_ (mortal, ::xml_schema::flags (), this),
    weight_ (weight, ::xml_schema::flags (), this),
    framesDelay_ (framesDelay, ::xml_schema::flags (), this),
    speed_ (speed, ::xml_schema::flags (), this),
    bitmap_ (bitmap, ::xml_schema::flags (), this),
    shadow_ (::xml_schema::flags (), this),
    extraFrames_ (::xml_schema::flags (), this),
    frame_ (::xml_schema::flags (), this),
    label_ (label, ::xml_schema::flags (), this)
  {
  }

  item::
  item (const item& x,
        ::xml_schema::flags f,
        ::xml_schema::type* c)
  : ::xml_schema::type (x, f, c),
    door_ (x.door_, f, this),
    widthX_ (x.widthX_, f, this),
    widthY_ (x.widthY_, f, this),
    height_ (x.height_, f, this),
    directionFrames_ (x.directionFrames_, f, this),
    mortal_ (x.mortal_, f, this),
    weight_ (x.weight_, f, this),
    framesDelay_ (x.framesDelay_, f, this),
    speed_ (x.speed_, f, this),
    bitmap_ (x.bitmap_, f, this),
    shadow_ (x.shadow_, f, this),
    extraFrames_ (x.extraFrames_, f, this),
    frame_ (x.frame_, f, this),
    label_ (x.label_, f, this)
  {
  }

  item::
  item (const ::xercesc::DOMElement& e,
        ::xml_schema::flags f,
        ::xml_schema::type* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    door_ (f, this),
    widthX_ (f, this),
    widthY_ (f, this),
    height_ (f, this),
    directionFrames_ (f, this),
    mortal_ (f, this),
    weight_ (f, this),
    framesDelay_ (f, this),
    speed_ (f, this),
    bitmap_ (f, this),
    shadow_ (f, this),
    extraFrames_ (f, this),
    frame_ (f, this),
    label_ (f, this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e);
      this->parse (p, f);
    }
  }

  void item::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // door
      //
      if (n.name () == "door" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< door_type > r (
          door_traits::create (i, f, this));

        if (!this->door ())
        {
          this->door (r);
          continue;
        }
      }

      // widthX
      //
      if (n.name () == "widthX" && n.namespace_ ().empty ())
      {
        this->widthX ().push_back (widthX_traits::create (i, f, this));
        continue;
      }

      // widthY
      //
      if (n.name () == "widthY" && n.namespace_ ().empty ())
      {
        this->widthY ().push_back (widthY_traits::create (i, f, this));
        continue;
      }

      // height
      //
      if (n.name () == "height" && n.namespace_ ().empty ())
      {
        this->height ().push_back (height_traits::create (i, f, this));
        continue;
      }

      // directionFrames
      //
      if (n.name () == "directionFrames" && n.namespace_ ().empty ())
      {
        if (!directionFrames_.present ())
        {
          this->directionFrames (directionFrames_traits::create (i, f, this));
          continue;
        }
      }

      // mortal
      //
      if (n.name () == "mortal" && n.namespace_ ().empty ())
      {
        if (!mortal_.present ())
        {
          this->mortal (mortal_traits::create (i, f, this));
          continue;
        }
      }

      // weight
      //
      if (n.name () == "weight" && n.namespace_ ().empty ())
      {
        if (!weight_.present ())
        {
          this->weight (weight_traits::create (i, f, this));
          continue;
        }
      }

      // framesDelay
      //
      if (n.name () == "framesDelay" && n.namespace_ ().empty ())
      {
        if (!framesDelay_.present ())
        {
          this->framesDelay (framesDelay_traits::create (i, f, this));
          continue;
        }
      }

      // speed
      //
      if (n.name () == "speed" && n.namespace_ ().empty ())
      {
        if (!speed_.present ())
        {
          this->speed (speed_traits::create (i, f, this));
          continue;
        }
      }

      // bitmap
      //
      if (n.name () == "bitmap" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< bitmap_type > r (
          bitmap_traits::create (i, f, this));

        if (!bitmap_.present ())
        {
          this->bitmap (r);
          continue;
        }
      }

      // shadow
      //
      if (n.name () == "shadow" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< shadow_type > r (
          shadow_traits::create (i, f, this));

        if (!this->shadow ())
        {
          this->shadow (r);
          continue;
        }
      }

      // extraFrames
      //
      if (n.name () == "extraFrames" && n.namespace_ ().empty ())
      {
        if (!this->extraFrames ())
        {
          this->extraFrames (extraFrames_traits::create (i, f, this));
          continue;
        }
      }

      // frame
      //
      if (n.name () == "frame" && n.namespace_ ().empty ())
      {
        this->frame ().push_back (frame_traits::create (i, f, this));
        continue;
      }

      break;
    }

    if (!directionFrames_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "directionFrames",
        "");
    }

    if (!mortal_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "mortal",
        "");
    }

    if (!weight_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "weight",
        "");
    }

    if (!framesDelay_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "framesDelay",
        "");
    }

    if (!speed_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "speed",
        "");
    }

    if (!bitmap_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "bitmap",
        "");
    }

    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "label" && n.namespace_ ().empty ())
      {
        this->label (label_traits::create (i, f, this));
        continue;
      }
    }

    if (!label_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "label",
        "");
    }
  }

  item* item::
  _clone (::xml_schema::flags f,
          ::xml_schema::type* c) const
  {
    return new item (*this, f, c);
  }

  // door
  //

  door::
  door (const ::xercesc::DOMElement& e,
        ::xml_schema::flags f,
        ::xml_schema::type* c)
  : ::xml_schema::string (e, f, c)
  {
    _xsd_door_convert ();
  }

  door::
  door (const ::xercesc::DOMAttr& a,
        ::xml_schema::flags f,
        ::xml_schema::type* c)
  : ::xml_schema::string (a, f, c)
  {
    _xsd_door_convert ();
  }

  door::
  door (const ::std::string& s,
        const ::xercesc::DOMElement* e,
        ::xml_schema::flags f,
        ::xml_schema::type* c)
  : ::xml_schema::string (s, e, f, c)
  {
    _xsd_door_convert ();
  }

  door* door::
  _clone (::xml_schema::flags f,
          ::xml_schema::type* c) const
  {
    return new door (*this, f, c);
  }

  door::value door::
  _xsd_door_convert () const
  {
    ::xsd::cxx::tree::enum_comparator< char > c (_xsd_door_literals_);
    const value* i (::std::lower_bound (
                      _xsd_door_indexes_,
                      _xsd_door_indexes_ + 4,
                      *this,
                      c));

    if (i == _xsd_door_indexes_ + 4 || _xsd_door_literals_[*i] != *this)
    {
      throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
    }

    return *i;
  }

  const char* const door::
  _xsd_door_literals_[4] =
  {
    "north",
    "south",
    "east",
    "west"
  };

  const door::value door::
  _xsd_door_indexes_[4] =
  {
    ::ixml::door::east,
    ::ixml::door::north,
    ::ixml::door::south,
    ::ixml::door::west
  };

  // bitmap
  //

  bitmap::
  bitmap (const frameWidth_type& frameWidth,
          const frameHeight_type& frameHeight,
          const file_type& file)
  : ::xml_schema::type (),
    frameWidth_ (frameWidth, ::xml_schema::flags (), this),
    frameHeight_ (frameHeight, ::xml_schema::flags (), this),
    file_ (file, ::xml_schema::flags (), this)
  {
  }

  bitmap::
  bitmap (const bitmap& x,
          ::xml_schema::flags f,
          ::xml_schema::type* c)
  : ::xml_schema::type (x, f, c),
    frameWidth_ (x.frameWidth_, f, this),
    frameHeight_ (x.frameHeight_, f, this),
    file_ (x.file_, f, this)
  {
  }

  bitmap::
  bitmap (const ::xercesc::DOMElement& e,
          ::xml_schema::flags f,
          ::xml_schema::type* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    frameWidth_ (f, this),
    frameHeight_ (f, this),
    file_ (f, this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e);
      this->parse (p, f);
    }
  }

  void bitmap::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // frameWidth
      //
      if (n.name () == "frameWidth" && n.namespace_ ().empty ())
      {
        if (!frameWidth_.present ())
        {
          this->frameWidth (frameWidth_traits::create (i, f, this));
          continue;
        }
      }

      // frameHeight
      //
      if (n.name () == "frameHeight" && n.namespace_ ().empty ())
      {
        if (!frameHeight_.present ())
        {
          this->frameHeight (frameHeight_traits::create (i, f, this));
          continue;
        }
      }

      break;
    }

    if (!frameWidth_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "frameWidth",
        "");
    }

    if (!frameHeight_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "frameHeight",
        "");
    }

    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "file" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< file_type > r (
          file_traits::create (i, f, this));

        this->file (r);
        continue;
      }
    }

    if (!file_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "file",
        "");
    }
  }

  bitmap* bitmap::
  _clone (::xml_schema::flags f,
          ::xml_schema::type* c) const
  {
    return new bitmap (*this, f, c);
  }

  // shadow
  //

  shadow::
  shadow (const shadowWidth_type& shadowWidth,
          const shadowHeight_type& shadowHeight,
          const file_type& file)
  : ::xml_schema::type (),
    shadowWidth_ (shadowWidth, ::xml_schema::flags (), this),
    shadowHeight_ (shadowHeight, ::xml_schema::flags (), this),
    file_ (file, ::xml_schema::flags (), this)
  {
  }

  shadow::
  shadow (const shadow& x,
          ::xml_schema::flags f,
          ::xml_schema::type* c)
  : ::xml_schema::type (x, f, c),
    shadowWidth_ (x.shadowWidth_, f, this),
    shadowHeight_ (x.shadowHeight_, f, this),
    file_ (x.file_, f, this)
  {
  }

  shadow::
  shadow (const ::xercesc::DOMElement& e,
          ::xml_schema::flags f,
          ::xml_schema::type* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    shadowWidth_ (f, this),
    shadowHeight_ (f, this),
    file_ (f, this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e);
      this->parse (p, f);
    }
  }

  void shadow::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // shadowWidth
      //
      if (n.name () == "shadowWidth" && n.namespace_ ().empty ())
      {
        if (!shadowWidth_.present ())
        {
          this->shadowWidth (shadowWidth_traits::create (i, f, this));
          continue;
        }
      }

      // shadowHeight
      //
      if (n.name () == "shadowHeight" && n.namespace_ ().empty ())
      {
        if (!shadowHeight_.present ())
        {
          this->shadowHeight (shadowHeight_traits::create (i, f, this));
          continue;
        }
      }

      break;
    }

    if (!shadowWidth_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "shadowWidth",
        "");
    }

    if (!shadowHeight_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "shadowHeight",
        "");
    }

    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "file" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< file_type > r (
          file_traits::create (i, f, this));

        this->file (r);
        continue;
      }
    }

    if (!file_.present ())
    {
      throw ::xsd::cxx::tree::expected_attribute< char > (
        "file",
        "");
    }
  }

  shadow* shadow::
  _clone (::xml_schema::flags f,
          ::xml_schema::type* c) const
  {
    return new shadow (*this, f, c);
  }
}

#include <istream>
#include <xercesc/framework/Wrapper4InputSource.hpp>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace ixml
{
  ::std::auto_ptr< ::ixml::ItemsXML >
  items (const ::std::string& u,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::tree::error_handler< char > h;

    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (u, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

    ::std::auto_ptr< ::ixml::ItemsXML > r (
      ::ixml::items (
        d.get (), f | ::xml_schema::flags::own_dom, p));

    if (f & ::xml_schema::flags::keep_dom)
      d.release ();

    return r;
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (const ::std::string& u,
         ::xml_schema::error_handler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (u, h, p, f));

    if (!d)
      throw ::xsd::cxx::tree::parsing< char > ();

    ::std::auto_ptr< ::ixml::ItemsXML > r (
      ::ixml::items (
        d.get (), f | ::xml_schema::flags::own_dom, p));

    if (f & ::xml_schema::flags::keep_dom)
      d.release ();

    return r;
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (const ::std::string& u,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (u, h, p, f));

    if (!d)
      throw ::xsd::cxx::tree::parsing< char > ();

    ::std::auto_ptr< ::ixml::ItemsXML > r (
      ::ixml::items (
        d.get (), f | ::xml_schema::flags::own_dom, p));

    if (f & ::xml_schema::flags::keep_dom)
      d.release ();

    return r;
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (::std::istream& is,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    ::xercesc::Wrapper4InputSource wrap (&isrc, false);
    return ::ixml::items (wrap, f, p);
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (::std::istream& is,
         ::xml_schema::error_handler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    ::xercesc::Wrapper4InputSource wrap (&isrc, false);
    return ::ixml::items (wrap, h, f, p);
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (::std::istream& is,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    ::xercesc::Wrapper4InputSource wrap (&isrc, false);
    return ::ixml::items (wrap, h, f, p);
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (::std::istream& is,
         const ::std::string& sid,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    ::xercesc::Wrapper4InputSource wrap (&isrc, false);
    return ::ixml::items (wrap, f, p);
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (::std::istream& is,
         const ::std::string& sid,
         ::xml_schema::error_handler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    ::xercesc::Wrapper4InputSource wrap (&isrc, false);
    return ::ixml::items (wrap, h, f, p);
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (::std::istream& is,
         const ::std::string& sid,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    ::xercesc::Wrapper4InputSource wrap (&isrc, false);
    return ::ixml::items (wrap, h, f, p);
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (const ::xercesc::DOMInputSource& i,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::tree::error_handler< char > h;

    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (i, h, p, f));

    h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

    ::std::auto_ptr< ::ixml::ItemsXML > r (
      ::ixml::items (
        d.get (), f | ::xml_schema::flags::own_dom, p));

    if (f & ::xml_schema::flags::keep_dom)
      d.release ();

    return r;
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (const ::xercesc::DOMInputSource& i,
         ::xml_schema::error_handler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (i, h, p, f));

    if (!d)
      throw ::xsd::cxx::tree::parsing< char > ();

    ::std::auto_ptr< ::ixml::ItemsXML > r (
      ::ixml::items (
        d.get (), f | ::xml_schema::flags::own_dom, p));

    if (f & ::xml_schema::flags::keep_dom)
      d.release ();

    return r;
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (const ::xercesc::DOMInputSource& i,
         ::xercesc::DOMErrorHandler& h,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d (
      ::xsd::cxx::xml::dom::parse< char > (i, h, p, f));

    if (!d)
      throw ::xsd::cxx::tree::parsing< char > ();

    ::std::auto_ptr< ::ixml::ItemsXML > r (
      ::ixml::items (
        d.get (), f | ::xml_schema::flags::own_dom, p));

    if (f & ::xml_schema::flags::keep_dom)
      d.release ();

    return r;
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (const ::xercesc::DOMDocument& d,
         ::xml_schema::flags f,
         const ::xml_schema::properties& p)
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > c (
        static_cast< ::xercesc::DOMDocument* > (d.cloneNode (true)));

      ::std::auto_ptr< ::ixml::ItemsXML > r (
        ::ixml::items (
          c.get (), f | ::xml_schema::flags::own_dom, p));

      c.release ();
      return r;
    }

    const ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (e));

    if (n.name () == "items" &&
        n.namespace_ () == "")
    {
      ::std::auto_ptr< ::ixml::ItemsXML > r (
        ::xsd::cxx::tree::traits< ::ixml::ItemsXML, char >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "items",
      "");
  }

  ::std::auto_ptr< ::ixml::ItemsXML >
  items (::xercesc::DOMDocument* d,
         ::xml_schema::flags f,
         const ::xml_schema::properties&)
  {
    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > c (
      ((f & ::xml_schema::flags::keep_dom) &&
       !(f & ::xml_schema::flags::own_dom))
      ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
      : 0);

    const ::xercesc::DOMElement& e (
      c.get ()
      ? *c->getDocumentElement ()
      : *d->getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (e));

    if (n.name () == "items" &&
        n.namespace_ () == "")
    {
      ::std::auto_ptr< ::ixml::ItemsXML > r (
        ::xsd::cxx::tree::traits< ::ixml::ItemsXML, char >::create (
          e, f, 0));
      c.release ();
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "items",
      "");
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue
//
//
// End epilogue

