

import requests
import pandas as pd


paperCsv_path = "article_information/6301ML_material.paperInfo.csv"
article_info = pd.read_csv(paperCsv_path, index_col=0)
save_path = "article_pdf/"

index = article_info.index.values
for i in index:
    if(article_info.loc[i, "pdf_link"] != None):
        requests_pdf_url = article_info.loc[i, "pdf_link"]
        try:
            r = requests.get(requests_pdf_url)
            print(requests_pdf_url)
            filename =  save_path + article_info.loc[i, "title"]+".pdf"
            article_info.loc[i, "Download_SuccessOrDefeat"] = "Success"
            with open(filename, 'wb+') as f:
                f.write(r.content)
        except:
            article_info.loc[i,  "Download_SuccessOrDefeat"] = "Defeat"
            continue
