/**
 * @file rtree.hpp
 * @brief Implementation of an R-tree. Work in progress
 *
 */

#ifndef GISCC_RTREE_HPP_
#define GISCC_RTREE_HPP_

#include <giscc/basealg.hpp>
#include <giscc/defs.hpp>
#include <giscc/primitives.hpp>

#include <vector>

class RTree2D {
  public:
    class RTreeNode {
      public:
        RTreeNode();

        ~RTreeNode();

      private:
        Rectangle2D resizeBoundingRectangle();
        Rectangle2D boundingRectangle;

        std::variant<std::vector<RTreeNode>, std::vector<Geometry>> entries;
    };

    // intialize with a collection of objects
    RTree2D(std::vector<Geometry>);

    // initialize with a bounding region
    RTree2D(Rectangle2D);

    // initialize with a default region
    RTree2D();

    // empty destructor
    ~RTree2D();

    // should make calls to resize
    bool insert();

    friend std::ostream& operator<<(std::ostream&, const RTree2D&);

    void print();

  private:
    RTreeNode __root__;
};

#endif // GISCC_RTREE_HPP_
