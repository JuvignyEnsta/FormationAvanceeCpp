#include <vector>
#include <array>
#include <optional>
#include <cmath>
#include <iostream>

struct Point 
{
    double x,y,z;
    Point( double const& t_x, double const& t_y, double const& t_z ) 
        :   x(t_x), y(t_y), z(t_z)
    {}
};

struct Vector 
{
    double x,y,z;
    Vector( Point const& t_p1, Point const& t_p2 )
        :   x(t_p2.x - t_p1.x),
            y(t_p2.y - t_p2.y),
            z(t_p2.z - t_p1.z)
    {}
    Vector( double t_x, double t_y, double t_z )
        :   x(t_x), y(t_y), z(t_z)
    {}

    double sqrNormL2() const { return x*x+y*y+z*z; }
};

struct Segment 
{
    Point  begSegment;
    Vector direction;
};

Vector operator * ( double a, Vector const& u )
{
    return { a*u.x, a*u.y, a*u.z };
}

Point operator + ( Point const& P, Vector const& u )
{
    return { P.x + u.x, P.y + u.y, P.z + u.z };
}

struct SegmentIntersectionData {
    std::optional<Point> intersectionNode;
    std::optional<double> t1, t2, t1min, t1max, t2min, t2max;
    bool has_intersection{false};
};

/**
 * @brief Calcule l'intersection entre deux segments en trois dimensions
 * @details
 *     On calcule le plus petit segment reliant les deux segments puis calcule les paramètres t1 et t2 donnant le point
 *     d'intersection pour les deux segments.
 * 
 * @param t_1stSegment Premier segment
 * @param t_2ndSegment Second  segment
 * @return SegmentIntersectionData 
 */
SegmentIntersectionData 
computeSegmentIntersection( Segment const& t_1stSegment, Segment const& t_2ndSegment ) {
    Vector const& P1P2 = t_1stSegment.direction;
    Vector const& P3P4 = t_2ndSegment.direction;
    if (P1P2.sqrNormL2() < 1.E-14 ) return {};
    if (P3P4.sqrNormL2() < 1.E-14 ) return {};
    Vector P3P1( t_2ndSegment.begSegment, t_1stSegment.begSegment);
    double d1343 = P3P1.x * P3P4.x + P3P1.y * P3P4.y + P3P1.z * P3P4.z;
    double d4321 = P3P4.x * P1P2.x + P3P4.y * P1P2.y + P3P4.z * P1P2.z;
    double d1321 = P3P1.x * P1P2.x + P3P1.y * P1P2.y + P3P1.z * P1P2.z;
    double d4343 = P3P4.sqrNormL2();
    double d2121 = P1P2.sqrNormL2();
    double denom = d2121 * d4343 - d4321 * d4321;
    if (std::abs(denom) < 1.E-6 ) 
    {
        // Les deux segments sont parallèles        
        return {};
    }
    double numer = d1343 * d4321 - d1321 * d4343;

    double ta = numer / denom;
    double tb = (d1343 + d4321 * ta )/d4343;

    if ( (ta < 0) or (ta>1) or (tb < 0) or (tb > 1) )
        return {};
    return { t_1stSegment.begSegment + ta * t_1stSegment.direction, ta, tb, {}, {}, {}, {}, true };
}

int main()
{
    Segment s1{ {0., 0., 0.}, {1.,0.,0.} }, s2{ {1.,-0.5,0.}, {0.,1.,0.} };    
    auto result = computeSegmentIntersection( s1, s2 );
    if (result.has_intersection)
    {
        if (result.intersectionNode.has_value())
        {
            std::cout << "Intersection entre les deux segments : ";
            Point const& interPt = result.intersectionNode.value();
            std::cout << "[" << interPt.x << ", " << interPt.y << ", " << interPt.z << "]" << std::endl;
        }
    }
    auto const& [intersectPt, t1, t2, t1Min, t1Max, t2Min, t2Max, hasIntersect]=computeSegmentIntersection(s1, s2);
    if (intersectPt.has_value())
    {
        Point const& interPt = intersectPt.value();
        std::cout << "Intersection entre les deux segments : [" << interPt.x << ", " << interPt.y << "," << interPt.z << "]" << std::endl;
    }
    return EXIT_SUCCESS;
}