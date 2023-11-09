function [img_salt_pepper_resize,height,width] = resize(origin_img, window_size)
n = window_size;
[height, width]=size(origin_img);
%��0����Ե���������߶�Ҫ������Ϊheight+n-1,width+n-1
img_salt_pepper_resize = zeros(height+n-1,width+n-1); 

%��resize���ͼ�������
for i=1+(n-1)/2:1+(n-1)/2+height-1
   for j=1+(n-1)/2:1+(n-1)/2+width-1
         img_salt_pepper_resize(i,j)=origin_img(i-(n-1)/2,j-(n-1)/2);
    end
end
end