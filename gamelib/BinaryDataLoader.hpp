#ifndef BINARYDATALOADER_HPP
#define BINARYDATALOADER_HPP

#include <string>
#include <fstream>

template <typename data_type>
class BinaryDataLoader {
	data_type *data;
protected:
	void SetData(data_type *newdata) {
		if (data == NULL) {
			data = newdata;
		}
	}
public:
	BinaryDataLoader()
	: data(NULL)
	{
		
	}

	virtual ~BinaryDataLoader() {
		if (data) {
			delete[] data;
		}
	}

	data_type const *GetData() {
		return data;
	}
};

#endif /* BINARYDATALOADER_HPP */

