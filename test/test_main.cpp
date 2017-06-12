#include "../include/optics/optics.h"
#include <vector>



void test_1(){
	static const int N = 2;
	typedef std::array<double, N> point; //A list of N cartesian coordinates makes a point

    std::vector<point> points; //Your list of points goes here
	points = { {100,100}, {102,100}, {101,101},           //cluster 1
			   {-1,0}, {1,0}, {0,1},                     //cluster 2
			   {-100,-100}, {-102,-100}, {-101,-101}     //cluster 3
	};
	auto reach_dists = optics::compute_reachability_dists( points, 2, 10 );
	for( const auto& x : reach_dists){
        std::cout << x.to_string() << "; ";
	}

	auto clusters = optics::get_cluster_indices(reach_dists, 10);
	assert(clusters.size() == 3);
	assert( ( fplus::sort( clusters[0] ) == std::vector <std::size_t>({ 0,1,2 }) ) );
	assert( ( fplus::sort( clusters[1] ) == std::vector <std::size_t>({ 3,4,5 }) ) );
	assert( ( fplus::sort( clusters[2] ) == std::vector <std::size_t>({ 6,7,8 }) ) );

	double epsilon_est = optics::epsilon_estimation( points, 2 );
	std::cout << "Epsilon-Estimation: " << epsilon_est << std::endl;
}

void test_2() {
	static const int N = 2;
	typedef std::array<int, N> point; //A list of N cartesian coordinates makes a point

	std::vector<point> points; //Your list of points goes here
	points = { { 100,100 },{ 102,100 },{ 101,101 },           //cluster 1
	{ -1,0 },{ 1,0 },{ 0,1 },                     //cluster 2
	{ -100,-100 },{ -102,-100 },{ -101,-101 }     //cluster 3
	};
	auto reach_dists = optics::compute_reachability_dists( points, 2 );
	for ( const auto& x : reach_dists ) {
		std::cout << x.to_string() << "; ";
	}

	auto clusters = optics::get_cluster_indices( reach_dists, 2 );
	assert( clusters.size() == 3 );
	assert( (fplus::sort( clusters[0] ) == std::vector <std::size_t>( { 0,1,2 } )) );
	assert( (fplus::sort( clusters[1] ) == std::vector <std::size_t>( { 3,4,5 } )) );
	assert( (fplus::sort( clusters[2] ) == std::vector <std::size_t>( { 6,7,8 } )) );

	double epsilon_est = optics::epsilon_estimation( points, 2 );
    std::cout << "Epsilon-Estimation: " << epsilon_est << std::endl;

	optics::draw_reachability_plot( reach_dists, "ReachabilityPlot" );
}

void test_3(){
    static const int N = 2;
	typedef std::array<unsigned char, N> point; //A list of N cartesian coordinates makes a point

    std::vector<point> points; //Your list of points goes here
	points = { {100,100}, {102,100}, {101,101},           //cluster 1
			   {1,1}, {1,0}, {0,1},                     //cluster 2
			   {200,100}, {202,100}, {201,101}     //cluster 3
	};

    auto reach_dists = optics::compute_reachability_dists( points, 2, 10 );

    auto clusters = optics::get_cluster_indices( reach_dists, 10 );
	assert( clusters.size() == 3 );
	assert( (fplus::sort( clusters[0] ) == std::vector <std::size_t>( { 0,1,2 } )) );
	assert( (fplus::sort( clusters[1] ) == std::vector <std::size_t>( { 3,4,5 } )) );
	assert( (fplus::sort( clusters[2] ) == std::vector <std::size_t>( { 6,7,8 } )) );

	auto cluster_points = optics::get_cluster_points(reach_dists, 10, points);
	auto img = optics::draw_2d_clusters(cluster_points);
	img.save("Clusters2d");
}

void test_4() {
	static const int N = 2;
	typedef std::array<double, N> point; //A list of N cartesian coordinates makes a point

	std::vector<point> points; //Your list of points goes here
	points = { { 0,0 },{ 1,0 },{ 0,1 },
	{ 10,0 },{ 0,10 },{ 6,6 },{ 4,4 },
	{ 10,10 },{ 9,10 },{ 10,9 }
	};

	double epsilon_est = optics::epsilon_estimation( points, 3 );
	assert( epsilon_est <3.090196 && epsilon_est >3.09019 );
}

void test_5() {
	static const int N = 3;
	typedef std::array<double, N> point; //A list of N cartesian coordinates makes a point

	std::vector<point> points; //Your list of points goes here
	points = { { 0,0,0 },{ 1,0,0 },{ 0,0,1 },{ 0,1,0 },
	{ 5,0,0 },{ 0,5,0 },{ 0,0,5 },{ 5,5,5 }
	};

	double epsilon_est = optics::epsilon_estimation( points, 3 );
	assert( epsilon_est >2.236750 && epsilon_est <2.236751 );
}


int main()
{
    test_1();

	test_2();

	test_3();

	test_4();

	test_5();
}
