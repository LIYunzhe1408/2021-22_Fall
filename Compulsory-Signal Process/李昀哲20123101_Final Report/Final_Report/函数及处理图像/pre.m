function [img_gray,img_salt_pepper] = pre(url, salt_rate)
%图像预处理，转为灰度图
img = imread(url);
img_gray = rgb2gray(img);

%添加噪音

img_salt_pepper=imnoise(img_gray,'speckle');

%img_salt_pepper=imnoise(img_gray,'gaussian');

%img_salt_pepper=imnoise(img_gray,'salt & pepper');
%img_salt_pepper=imnoise(img_gray,'salt & pepper',salt_rate);
end