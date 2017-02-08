#include "Component.h"
#include <iostream>
using namespace std;

SwbComponent::SwbComponent()
{
}

SwbComponent::~SwbComponent()
{
}

void SwbComponent::Add(SwbComponent* com)
{
	cout<<"Component::Add..."<<endl;
}

void SwbComponent::Remove(SwbComponent* com)
{
	cout<<"Component::Remove..."<<endl;
}

SwbComponent* SwbComponent::GetChild(int index)
{
	return NULL;
}
