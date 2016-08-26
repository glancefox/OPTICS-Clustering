// Copyright 2015, Tobias Hermann and the FunctionalPlus contributors.
// https://github.com/Dobiasd/FunctionalPlus
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <optics/optics.h>
#include <vector>

using namespace testing;

TEST(reachability_test, a)
{
	typedef std::vector<double> point; //A list of n cartesian coordinates makes a point
	std::vector<point> points; //Your list of points goes here
	points = { {100,100}, {102,100}, {101,101},           //cluster 1
			   {-1,0}, {1,0}, {0,1},                     //cluster 2
			   {-100,-100}, {-102,-100}, {-101,-101}     //cluster 3
	};
	auto reach_dists = optics::compute_reachability_dists<double,2>( points, 2, 10 );
	optics::draw_reachability_plot( reach_dists, "reachdists.bmp" );
	
	EXPECT_THAT(42, Eq(42)); // todo
}