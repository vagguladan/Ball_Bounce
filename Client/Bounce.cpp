#include "Bounce.h"
#include "yaTime.h"



namespace ya
{

	std::vector<Bounce::Direct> Bounce::mDriect = {};

	std::vector<math::Vector2> Bounce::mVector2 = {};

	float timeCheck = 0.0f;
	int Ball = 0;

	//이것을 만든이유. 초기값을 만들기위해.
	//하나를 움직이는것. ture false 

	void Bounce::Initailize()
	{

		srand(time(NULL));

		int RandX = rand();
		int RandY = rand();

		

		Direct direct = {};

		if (RandX % 2 == 0)
		{
			direct.DirectX = false;
		}
		else
			direct.DirectX = true;

		if (RandY % 2 == 0)
		{
			direct.DirectY = false;
		}
		else
			direct.DirectY = true;

		mDriect.push_back(direct);
		
		math::Vector2 vector2 = {};

		vector2.x = 0.0f;
		vector2.y = 0.0f;

		mVector2.push_back(vector2);

		

	}
	void Bounce::Update()
	{

		timeCheck += Time::DeltaTime();

		if(timeCheck>1.0f)
		{
			Direct direct = {};
			srand(time(NULL));
			int RandX = rand();
			int RandY = rand();

			if (RandX % 2 == 0)
			{
				direct.DirectX = false;
			}
			else
				direct.DirectX = true;

			if (RandY % 2 == 0)
			{
				direct.DirectY = false;
			}
			else
				direct.DirectY = true;


			mDriect.push_back(direct);

			math::Vector2 vector2 = {};

			vector2.x = 0.0f;
			vector2.y = 0.0f;

			mVector2.push_back(vector2);

			Ball += 1;
			timeCheck = 0.0f;
		}

	for (int a = 0; a <= Ball; a++)
	{ 
		srand(time(NULL));

		if (mDriect[a].DirectX == true)
		{
			//mVector2[a].x -= 600.0f * Time::DeltaTime();
			mVector2[a].x -= rand()%600 * Time::DeltaTime();
		}
		if (mDriect[a].DirectX == false)
		{
			//mVector2[a].x += 600.0f * Time::DeltaTime();
			mVector2[a].x += rand() % 600 * Time::DeltaTime();
		}
		if (mDriect[a].DirectY == true)
		{
			//mVector2[a].y -= 300.0f * Time::DeltaTime();
			mVector2[a].y -= rand() % 600 * Time::DeltaTime();
		}
		if (mDriect[a].DirectY == false)
		{
			//mVector2[a].y += 600.0f * Time::DeltaTime();
			mVector2[a].y += rand() % 600 * Time::DeltaTime();
		}

		if (mVector2[a].x + 200 > 1600)
		{
			mDriect[a].DirectX = true;

		}

		if (mVector2[a].x + 100 < 0)
		{
			mDriect[a].DirectX = false;
		}

		if (mVector2[a].y + 250 > 900)
		{
			mDriect[a].DirectY = true;

		}

		if (mVector2[a].y + 100 < 0)
		{
			mDriect[a].DirectY = false;
		}
	}

		

	}
	void Bounce::Render(HDC hdc)
	{
	//int SummonEX = rand() % 1600;
		//int SummonEY = rand() % 1600;

		for (int a = 0; a <= Ball; a++)
		{

		
		Ellipse(hdc, 100 + mVector2[a].x, 100 + mVector2[a].y
			, 200 + mVector2[a].x, 200 + mVector2[a].y);

		}
	}
}