import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    table = customers.merge(orders, how="left", left_on="id", right_on="customerId")
    return table[table["id_y"].isna()][["name"]].rename(columns = {"name" : "Customers"})